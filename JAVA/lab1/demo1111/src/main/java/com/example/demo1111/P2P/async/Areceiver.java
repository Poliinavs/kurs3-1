package com.example.demo1111.P2P.async;


import javax.jms.*;

import com.sun.messaging.ConnectionFactory;
import com.sun.messaging.ConnectionConfiguration;

public class Areceiver implements MessageListener {
    private ConnectionFactory factory = new ConnectionFactory();
    private JMSConsumer consumer;

    Areceiver() {
        try (JMSContext context = factory.createContext("admin", "admin")) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");
            Destination messageQueue = context.createQueue("AsyncQueue");

            consumer = context.createConsumer(messageQueue);
            consumer.setMessageListener(this);                                   //устанавливаем в ожидание сообщений
            System.out.println("Listening to AsyncQueue");
            while (true) {
                Thread.sleep(1000);
            }
        } catch (InterruptedException | JMSException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void onMessage(javax.jms.Message message) {                          //вызываается, когда приходит сообщение
        try {
            System.out.println("Receive message: "+
                    message.getBody(com.example.demo1111.P2P.Message.class));
            System.out.println("\n toString() for message\n"+ message);

        } catch (Exception e) {
            System.err.println("JMSException: " + e.toString());
        }
    }

    public static void main (String[] args){
        new Areceiver();
    }
}