package com.example.demo1111.pub_sub.prior;


import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.Destination;
import javax.jms.JMSContext;
import javax.jms.JMSException;

public class Sender1 {
    public static void main(String[] args){
        ConnectionFactory factory= new ConnectionFactory();
        try(JMSContext context = factory.createContext("admin", "admin")){
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676,mq://127.0.0.1:7676");
            Destination priceInfo  = context.createTopic("PubSub");
            while (true) {
                System.out.println("message sent");
                context.createProducer().setPriority(9).send(priceInfo, "message with priority 9");
                Thread.sleep(1000);
            }
        } catch (JMSException | InterruptedException e) {
            System.out.println("ConnectionConfigurationError: " + e.getMessage());
        }
    }
}