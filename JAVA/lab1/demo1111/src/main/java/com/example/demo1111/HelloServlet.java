package com.example.demo1111;

import java.io.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.Destination;
import javax.jms.JMSContext;
import javax.jms.JMSException;
@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    private String message;

    public void init() {
        message = "Hello World!";
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)  throws IOException {
        ConnectionFactory factory= new ConnectionFactory();
        String message = request.getParameter("message");
        try(JMSContext context = factory.createContext("admin", "admin")){
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676,mq://127.0.0.1:7676");
            Destination priceInfo  = context.createTopic("PubSub");
            context.createProducer().send(priceInfo, message);
            System.out.println("message  sent");
        } catch (JMSException e) {
            System.out.println("ConnectionConfigurationError: " + e.getMessage());
        }
    }

    public void destroy() {
    }
}