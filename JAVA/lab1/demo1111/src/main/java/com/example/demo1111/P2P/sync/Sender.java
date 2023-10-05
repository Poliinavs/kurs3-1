package com.example.demo1111.P2P.sync;

import com.example.demo1111.P2P.Message;
import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.*;
import java.util.Date;

public class Sender {
    public static void main(String[] args){
        ConnectionFactory factory= new ConnectionFactory();

        try(JMSContext context = factory.createContext("admin", "admin")){
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676,mq://127.0.0.1:7676");

            Destination messagesQueue = context.createQueue("SyncQueue");
            Message message = new Message("Hello MOM");
            ObjectMessage objMsg = context.createObjectMessage(message);

            JMSProducer producer = context.createProducer();
            producer.send(messagesQueue, objMsg);
            System.out.println("message sent");

        } catch (JMSException e) {
            System.out.println("ConnectionConfigurationError: " + e.getMessage());
        }
    }
}