package com.example.demo1111.P2P;

import java.io.Serializable;
import java.util.Date;

public class  Message implements Serializable {
    private String text;

    @Override
    public String toString() {
        return "Message : " + text ;
    }

    public Message(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }


}