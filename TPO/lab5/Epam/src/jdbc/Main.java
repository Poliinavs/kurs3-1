package jdbc;

import java.sql.Connection;
import java.sql.SQLException;

import static jdbc.WeatherQuery.*;

public class Main {

    public static void main(String[] args) {
        try {
            // Получаем соединение с базой данных
            Connection connection = DatabaseConnection.getConnection();

            getSnowDates(connection, "Region1", 0); // Пример 1
            getWeatherInfoByLanguage(connection, "Language1"); // Пример 2
            getAverageTemperatureByArea(connection, 900); // Пример 3



            // Закрываем соединение после использования
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
