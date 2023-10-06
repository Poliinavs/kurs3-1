package com.example.lab2.controller;
import com.example.lab2.forms.PersonForm;
import com.example.lab2.model.Person;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.util.ArrayList;
import java.util.List;
@Slf4j
@Controller

@RequestMapping
public class PersonController {

    public static List<Person> Persons = new ArrayList<Person>();

    static {
        Persons.add(new Person("Abramov", "Igor"));
        Persons.add(new Person("Grigor", "Daria"));
    }

    //
    // Вводится (inject) из application.properties.
    @Value("${welcome.message}")
    private String message;

    @Value("${error.message}")
    private String errorMessage;

       @GetMapping(value = {"/", "/index"})
    public ModelAndView index(Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        model.addAttribute("message", message);
        log.info("/index was called");

        return modelAndView;

    }

    @GetMapping(value = {"/allpersons"})
    public ModelAndView personList(Model model) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("personlist");
        model.addAttribute("persons", Persons);
        log.info("/allpersons was called");
        return modelAndView;
    }


    @GetMapping(value = {"/addperson"})
    public  ModelAndView showAddPersonPage(Model model) {
        ModelAndView modelAndView = new ModelAndView("addperson");
        PersonForm PersonForm = new PersonForm();
        model.addAttribute("personForm", PersonForm);
        log.info("/addperson was called");

        return modelAndView;
    }
    @RequestMapping(value = {"/delperson"}, method = RequestMethod.GET)
    public  ModelAndView showDelPersonPage(Model model) {
        ModelAndView modelAndView = new ModelAndView("delperson");
        PersonForm PersonForm = new PersonForm();
        model.addAttribute("personForm", PersonForm);
        log.info("/delperson was called");

        return modelAndView;
    }
    @RequestMapping(value = {"/removeperson"}, method = RequestMethod.GET)
    public  ModelAndView removeDelPersonPage(Model model) {
        ModelAndView modelAndView = new ModelAndView("removeperson");
        PersonForm PersonForm = new PersonForm();
        model.addAttribute("personForm", PersonForm);
        log.info("/removeperson was called");

        return modelAndView;
    }
    //  @PostMapping("/addbook")
//GetMapping("/")
    @PostMapping(value = {"/addperson"})
    public ModelAndView savePerson(Model model, //
                                   @ModelAttribute("personForm") PersonForm personForm) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("personlist");
       String firstname = personForm.getSurname();
       String surname = personForm.getFirstname();

        if (firstname != null && firstname.length() > 0 //
                && surname != null && surname.length() > 0) {
            Person newPerson = new Person(firstname, surname);
            Persons.add(newPerson);
            model.addAttribute("persons",Persons);
            return modelAndView;
        }
        model.addAttribute("errorMessage", errorMessage);
        modelAndView.setViewName("addperson");
        return modelAndView;
  }

    @PostMapping(value = {"/delperson"})
    public ModelAndView delPerson(Model model, //
                                   @ModelAttribute("personForm") PersonForm personForm) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("personlist");
        String firstname = personForm.getSurname();
        String surname = personForm.getFirstname();

        if (firstname != null && firstname.length() > 0 //
                && surname != null && surname.length() > 0) {
            Person newPerson = new Person(firstname, surname);
            if (Persons.contains(newPerson)) {
                Persons.remove(newPerson);
            } else {
                model.addAttribute("errorMessage", "NO people");
                modelAndView.setViewName("delperson");
                return modelAndView;
            }


            model.addAttribute("persons",Persons);
            return modelAndView;
        }
        model.addAttribute("errorMessage", errorMessage);
        modelAndView.setViewName("addperson");
        return modelAndView;
    }

    @PostMapping(value = {"/removeperson"})
    public ModelAndView removePerson(Model model, //
                                  @ModelAttribute("personForm") PersonForm personForm) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("personlist");
        String newname  = personForm.getSurname();
        String firstname = personForm.getFirstname();

        if (firstname != null && firstname.length() > 0 //
                && newname != null && newname.length() > 0) {

            for (Person existingPerson : Persons) {
                if (existingPerson.getFirstname().equals(firstname)) {

                    existingPerson.setFirstname(newname);
                    model.addAttribute("persons",Persons);
                    return modelAndView;

                }
            }
            model.addAttribute("errorMessage", "No person with that name");
            modelAndView.setViewName("removeperson");
            return modelAndView;


        }
        model.addAttribute("errorMessage", errorMessage);
        modelAndView.setViewName("removeperson");
        return modelAndView;
    }








}
