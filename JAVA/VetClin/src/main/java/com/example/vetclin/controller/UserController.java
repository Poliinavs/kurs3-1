package com.example.vetclin.controller;

import ch.qos.logback.core.model.Model;
import com.example.vetclin.Repozitor.UserRepository;
import com.example.vetclin.model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@RestController
public class UserController {
    private final UserRepository userRepository;

    @Autowired
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @GetMapping("/users")
    public String getAllUsers(Model model) {
        List<User> users = userRepository.findAll();
        model.addAttribute("users", users);
        return "userlist";
    }
    @GetMapping(value = {"/allusers"})
    public ModelAndView personList(org.springframework.ui.Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("userlist");

        model.addAttribute("Users", users);
      //  log.info("/allpersons was called");
        return modelAndView;
    }

}