package com.example.demo1111.pub_sub.Durable;

import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;

import javax.jms.*;

public class Receiver implements MessageListener { //долгосрочная подписка
    private ConnectionFactory factory = new ConnectionFactory();
    private JMSConsumer consumer;

    Receiver() {
        try (JMSContext context = factory.createContext("admin", "admin", JMSContext.AUTO_ACKNOWLEDGE)) {
            factory.setProperty(ConnectionConfiguration.imqAddressList,
                    "mq://127.0.0.1:7676, mq://127.0.0.1:7676");

            // Устанавливаем клиентский идентификатор
            context.setClientID("client123423");

            // Создаем тему
            Topic priceInfo = context.createTopic("PubSub");

            // Создаем долгосрочного подписчика
            consumer = context.createDurableConsumer(priceInfo, "SubscriptionName");

            // Устанавливаем этот объект в качестве слушателя сообщений
            consumer.setMessageListener(this);

            System.out.println("Listening to PubSub topic");

            // Ожидаем сообщения в бесконечном цикле
            while (true) {
                Thread.sleep(1000);
            }
        } catch (JMSException | InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void onMessage(javax.jms.Message message) {
        try {
            System.out.println("Received message: " + message.getBody(String.class));
        } catch (Exception e) {
            System.err.println("JMSException: " + e.toString());
        }
    }

    public static void main(String[] args) {
        new Receiver();
    }
}
