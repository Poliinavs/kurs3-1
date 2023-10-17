package Thread;

import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
class Port {
    public int capacity; // Вместимость порта
    private int containers; // Текущее количество контейнеров в порту
    private Semaphore dockSemaphore; // Семафор для управления доступом к причалам

    public Port(int capacity, int initialContainers, int numDocks) {
        this.capacity = capacity;
        this.containers = initialContainers;
        this.dockSemaphore = new Semaphore(numDocks, true);
    }

    public synchronized int getAvailableContainers() {
        return capacity - containers;
    }

    public void loadContainers(int amount) {
        synchronized (this) {
            if (containers + amount <= capacity) {
                containers += amount;
                System.out.println("Контейнеры загружены: " + amount);
            } else {
                System.out.println("Недостаточно места для загрузки " + amount + " контейнеров.");
            }
        }
    }

    public void unloadContainers(int amount) {
        synchronized (this) {
            if (containers >= amount) {
                containers -= amount;
                System.out.println("Контейнеры разгружены: " + amount);
            } else {
                System.out.println("Недостаточно контейнеров для разгрузки " + amount + " контейнеров.");
            }
        }
    }

    public boolean dockShip() {
        return dockSemaphore.tryAcquire();
    }

    public void undockShip() {
        dockSemaphore.release();
    }
}

class Ship implements Runnable {
    private String name;
    private int capacity; // Грузоподъемность корабля
    private int containers; // Количество контейнеров на корабле
    private Port port;

    public Ship(String name, int capacity, int containers, Port port) {
        this.name = name;
        this.capacity = capacity;
        this.containers = containers;
        this.port = port;
    }

    @Override
    public void run() {
        System.out.println(name + " прибыл в порт.");
        if (port.dockShip()) {
            System.out.println(name + " пришвартовался к причалу.");
            int loadAmount =0;

            if(port.getAvailableContainers()>capacity - containers){ //загружаем все контейнеры тк место есть
                loadAmount =capacity - containers;
            }
            else{
                loadAmount =port.getAvailableContainers();  //закгружаем на всю вместительность
            }

            port.loadContainers(loadAmount);
            containers += loadAmount;

            int unloadAmount = Math.min(containers, port.capacity); //или все контейнеры с корабля или полный порт
            port.unloadContainers(unloadAmount);
            containers -= unloadAmount;

            port.undockShip();
            System.out.println(name + " отошел от причала.");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Port port = new Port(100, 50, 3);
        ExecutorService executor = Executors.newFixedThreadPool(5); // создает пул из 5 потоков

        for (int i = 1; i <= 5; i++) {
            Ship ship = new Ship("Корабль " + i, 30, 0, port);
            executor.execute(ship);  //добавлен в очередь выполнения пула потоков.
        }

        executor.shutdown();
        // Ожидание завершения всех потоков
        while (!executor.isTerminated()) {

        }


        System.out.println("Все корабли пришвартовались и отгрузились.");

    }
}
