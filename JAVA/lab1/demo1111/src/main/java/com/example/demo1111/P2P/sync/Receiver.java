package com.example.demo1111.P2P.sync;


import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.*;

public class Receiver {
    private ConnectionFactory factory = new ConnectionFactory();     //соединение с jms
    private JMSConsumer consumer;                       //для получен сообщен

    Receiver() {
        try (JMSContext context = factory.createContext("admin", "admin")) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");
            Destination messageQueue = context.createQueue("SyncQueue");                     //создается очередь синхронная
            consumer = context.createConsumer(messageQueue);                                  //создается получатель для этой очереди
            Message message = consumer.receive();                                           //получаем сообщение
            System.out.println("Listening to SyncQueue");
            System.out.println("New Message: "+ message.getBody(com.example.demo1111.P2P.Message.class));     //преобразование к типу Messege
            System.out.println("\nToString for message \n"+ message);
            while (true) {
                Thread.sleep(1000);
            }
        } catch (InterruptedException | JMSException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main (String[] args){
        new Receiver();
    }
}