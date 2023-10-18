package com.example.vetclin.forms;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class userform {
    private int id;
    private String login;
    private String password;
    private String email;
}
