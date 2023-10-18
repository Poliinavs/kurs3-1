package com.example.vetclin.controller;/*
package com.example.vetclin.controller;

import com.example.vetclin.Repozitor.UserRepository;
import com.example.vetclin.model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@RequestMapping("/users")
public class UserController {
    private final UserRepository userRepository;

    @Autowired
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }
    @GetMapping("/hello")
    public ModelAndView showHelloList(Model model) {
     //   List<User> users = userRepository.getAllUsers();
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("hello");


        return modelAndView;

    }
    @GetMapping("/userlist")
    public ModelAndView showUserList(Model model) {
        List<User> users = userRepository.getAllUsers();
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("userlist");
        model.addAttribute("users", users);

        return modelAndView;

       */
/* List<User> users = userRepository.getAllUsers();
        model.addAttribute("users", users);
        return "userlist"; // Имя Thymeleaf шаблона*//*

    }
}*/

import com.example.vetclin.Repozitor.UserRepository;
import com.example.vetclin.forms.userform;
import com.example.vetclin.model.User;
import lombok.extern.slf4j.Slf4j;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.jdbc.UncategorizedSQLException;
import org.springframework.jdbc.core.JdbcOperations;
import org.springframework.jdbc.core.SqlOutParameter;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.sql.Types;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.logging.Logger;

@Slf4j
@Controller
public class UserController {

    private final UserRepository userRepository;

    @Autowired
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    private String errorMessage="Fill in all the fields";

   // private static final Logger logger = (Logger) LoggerFactory.getLogger(UserController.class);
/*    private static final org.slf4j.Logger log =
            org.slf4j.LoggerFactory.getLogger(UserController.class);*/


    @GetMapping(value = {"/", "/index"})
    public ModelAndView index(Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        return modelAndView;

    }


    @GetMapping(value = { "/Login"})
    public ModelAndView Login(Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("Login");
        User user = new User();
        model.addAttribute("user", user);
        return modelAndView;
    }

    @PostMapping(value = {"/addUser"})
    public ModelAndView savePerson(Model model, @ModelAttribute("user") User user) {
        ModelAndView modelAndView = new ModelAndView();
        model.addAttribute("user", user);
        modelAndView.setViewName("Login");
        String email = user.getEmail();
        String password = user.getPassword();
        String login = user.getLogin();

        //  logger.info("/addUser was called");

        if (email != null && email.length() > 0
                && password != null && password.length() > 0
                && login != null && login.length() > 0) {

            Map<String, Object> inParams = new HashMap<>();
            inParams.put("LOGIN_P", login);
            inParams.put("EMAIL_P", email);
            inParams.put("PASS_P", password);

            try {
                String result = userRepository.callAuthPackageProcedure("REGISTRATION", inParams);

                model.addAttribute("errorMessage", "Успешно!!!!!!!!!!");
            } catch (UncategorizedSQLException e) {
                model.addAttribute("callToggleStyles", true);
                String errorMessage = e.getMessage();
                if (errorMessage.contains("ORA-20001")) {
                    model.addAttribute("errorMessage", "Пользователь с таким адресом электронной почты уже существует");
                } else if (errorMessage.contains("ORA-20002")) {
                    model.addAttribute("errorMessage", "Пользователь с таким логином уже существует");
                } else if (errorMessage.contains("ORA-20003")) {
                    model.addAttribute("errorMessage", "Ошибка при проверке введенных данных");
                } else if (errorMessage.contains("ORA-20000")) {
                    model.addAttribute("errorMessage", "Введен некорректный адрес электронной почты");
                } else {
                    model.addAttribute("errorMessage", "Произошла ошибка при выполнении процедуры");
                }

            }
            return modelAndView;
        }
        model.addAttribute("errorMessage", errorMessage);
        return modelAndView;
    }
    @PostMapping(value = {"/loginUser"})
    public ModelAndView loginPerson(Model model, @ModelAttribute("user") User user) {
        ModelAndView modelAndView = new ModelAndView();
        model.addAttribute("user", user);
        modelAndView.setViewName("Login");
        String password = user.getPassword();
        String login = user.getLogin();

        if (password != null && password.length() > 0 && login != null && login.length() > 0) {
            // Вызов функции для проверки входа
            int userId = userRepository.callLoginFunction(login, password);

            if (userId > 0) {
                // Вход выполнен успешно
                model.addAttribute("errorMessage", "Успешный вход");
            } else {
                // Неверный логин/пароль или другая ошибка
                model.addAttribute("callToggleStyles", true);
                model.addAttribute("errorMessage", "Ошибка входа. Пожалуйста, проверьте логин и пароль.");
            }
        } else {
            model.addAttribute("errorMessage", "Необходимо заполнить все поля.");
        }

        return modelAndView;
    }

















    @GetMapping(value = { "/userlist"})
    public ModelAndView hello(Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("userlist");
        List<User> users = userRepository.getAllUsers();


        model.addAttribute("users", users);
        //  model.addAttribute("message", message);

        return modelAndView;

    }


    @GetMapping(value = { "/test"})
    public ModelAndView test(Model model) {
        ModelAndView modelAndView = new ModelAndView("test");
        User user = new User();
        model.addAttribute("user", user);

        return modelAndView;
    }


    @PostMapping("/signIn")
    public Integer login(@RequestParam String username, @RequestParam String password) {
        // Вызов функции LOGIN из базы данных
        JdbcOperations jdbcTemplate;
        Integer userId = UserRepository.getJdbcTemplate().queryForObject(
                "BEGIN ? := AuthPackage.LOGIN(?, ?); END;",
                Integer.class,
                new SqlOutParameter("1", Types.INTEGER),
                username,
                password
        );

        // Обработка результата
        return userId;
    }

    @PostMapping(value = {"/test"})
    public  ModelAndView showAddTest(Model model) {
        ModelAndView modelAndView = new ModelAndView("test");
        User user = new User();
        model.addAttribute("user", user);

        return modelAndView;
    }




}
