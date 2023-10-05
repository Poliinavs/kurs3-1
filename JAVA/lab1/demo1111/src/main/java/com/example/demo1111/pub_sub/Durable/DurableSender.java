package com.example.demo1111.pub_sub.Durable;


import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.Destination;
import javax.jms.JMSContext;
import javax.jms.JMSException;

public class DurableSender {
    public static void main(String[] args){
        ConnectionFactory factory= new ConnectionFactory();
        try(JMSContext context = factory.createContext("admin", "admin")){
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676,mq://127.0.0.1:7676");


            Destination priceInfo  = context.createTopic("PubSub");      //задаем тему, клинеты подписанные на нее будут получать сообщения
            context.createProducer().send(priceInfo, "Hello PubSub");
            System.out.println("message  sent");
        } catch (JMSException e) {
            System.out.println("ConnectionConfigurationError: " + e.getMessage());
        }
    }
}