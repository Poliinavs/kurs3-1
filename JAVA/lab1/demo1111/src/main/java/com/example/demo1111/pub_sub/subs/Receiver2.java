package com.example.demo1111.pub_sub.subs;

//import com.sun.messaging.ConnectionConfiguration;
//import com.sun.messaging.ConnectionFactory;
//
//import javax.jms.*;
//
//public class Receiver2 implements MessageListener {
//    private ConnectionFactory factory = new ConnectionFactory();
//    private JMSConsumer consumer;
//
//    Receiver2() {
//        try (JMSContext context = factory.createContext("admin", "admin")) {
//            factory.setProperty(ConnectionConfiguration.imqAddressList,
//                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");
//            Destination priceInfo= context.createTopic("PubSub");
//            //context.setClientID("client123");
//            consumer = context.createConsumer(priceInfo);
//            consumer.setMessageListener(this);
//            while (true) {
//                Thread.sleep(1000);
//            }
//        } catch (JMSException | InterruptedException e) {
//            System.out.println(e.getMessage());
//        }
//    }
//
//    @Override
//    public void onMessage(Message message) {
//        try {
//            System.out.println("Reciever 1 : "+ message.getBody(String.class));
//        } catch (Exception e) {
//            System.err.println("JMSException: " + e.toString());
//        }
//    }
//
//    public static void main (String[] args){
//        new Receiver2();
//    }
//}


import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.*;

public class Receiver2 implements MessageListener {
    private ConnectionFactory factory = new ConnectionFactory();
    private JMSConsumer consumer;

    Receiver2() {
        try (JMSContext context = factory.createContext("admin", "admin")) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");
            Destination priceInfo= context.createTopic("PubSub");
            consumer = context.createConsumer(priceInfo);
            String selector = "symbol=BST222U";
            context.createConsumer(priceInfo, selector);

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
            System.out.println("Reciever 2 : "+ message.getBody(String.class));
        } catch (Exception e) {
            System.err.println("JMSException: " + e.toString());
        }
    }

    public static void main (String[] args){
        new Receiver2();
    }
}