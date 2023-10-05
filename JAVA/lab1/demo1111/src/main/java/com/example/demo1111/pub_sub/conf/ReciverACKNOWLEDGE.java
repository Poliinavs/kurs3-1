package com.example.demo1111.pub_sub.conf;


import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.*;

public class ReciverACKNOWLEDGE implements MessageListener {
    private ConnectionFactory factory = new ConnectionFactory();
    private JMSConsumer consumer;

    ReciverACKNOWLEDGE() {
        try (JMSContext context = factory.createContext("admin", "admin", JMSContext.CLIENT_ACKNOWLEDGE)) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");
            Destination priceInfo= context.createTopic("PubSub");
            consumer = context.createConsumer(priceInfo);
            consumer.setMessageListener(this);
            while (true) {
                Thread.sleep(1000);
            }
        } catch (JMSException | InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void onMessage(Message message) {
        try {
            System.out.println("ReciverACKNOWLEDGE : "+ message.getBody(String.class));
        } catch (Exception e) {
            System.err.println("JMSException: " + e.toString());
        }
    }

    public static void main (String[] args){
        new ReciverACKNOWLEDGE();
    }
}