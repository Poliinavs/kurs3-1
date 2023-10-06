package com.example.lab2.forms;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class PersonForm {
    private String surname;
    private String firstname;


    public String getSurname() {
        return surname;
    }

    public String getFirstname() {
        return firstname;
    }
}
