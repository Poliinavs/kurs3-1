package com.example.demo1111.pub_sub.Durable;
import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory; // Импортируйте правильный пакет

import javax.jms.*;

public class Receiver {
    public static void main(String[] args) {
        ConnectionFactory factory = new com.sun.messaging.ConnectionFactory();

        try (JMSContext context = factory.createContext("admin", "admin")) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676,mq://127.0.0.1:7676");
            Destination priceInfo = context.createTopic("DurableTopic");

            // Создание подписчика с уникальным именем клиента
            JMSConsumer consumer = context.createDurableConsumer((Topic) priceInfo, "MyDurableSubscription");

            while (true) {
                TextMessage message = (TextMessage) consumer.receive();
                if (message != null) {
                    System.out.println("Received message: " + message.getText());
                }
            }
        } catch (JMSException e) {
            System.out.println("JMS Error: " + e.getMessage());
        }
    }
}
