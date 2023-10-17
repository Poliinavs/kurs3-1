package jdbc;

import java.sql.*;

public class WeatherQuery {
   /* public static void getWeatherInfoByRegion(Connection connection, String regionName) {
        String query = "SELECT * FROM Weather w JOIN Region r ON w.region_id = r.region_id WHERE r.name = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, regionName);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {

                int weatherId = resultSet.getInt("weather_id");
                String weatherDescription = resultSet.getString("precipitation");
                Date date = resultSet.getDate("date");
                double temperature = resultSet.getDouble("temperature");

                // Вывод результатов на консоль
                System.out.println("Weather ID: " + weatherId);
                System.out.println("Description: " + weatherDescription);
                System.out.println("Date: " + date);
                System.out.println("Temperature: " + temperature);
                System.out.println("------------------------------");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
*/
  // Вывести среднюю температуру за прошедшую неделю в регионах с площадью больше заданной:
   public static void getAverageTemperatureByArea(Connection connection, float minArea) {
       // Предположим, что текущая дата - это конец прошедшей недели
       // Вам может понадобиться уточнить, как определить начало и конец недели в вашей базе данных
       Date currentDate = new Date(System.currentTimeMillis()); // Текущая дата
       Date startDate = null; // Начало недели

       String query = "SELECT r.name, AVG(w.temperature) AS avg_temperature " +
               "FROM Weather w " +
               "JOIN Region r ON w.region_id = r.region_id " +
               "WHERE r.area > ? AND w.date BETWEEN ? AND ? " +
               "GROUP BY r.name";
       try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
           preparedStatement.setFloat(1, minArea);
           preparedStatement.setDate(2, startDate);
           Date endDate= new Date(System.currentTimeMillis());
           preparedStatement.setDate(3, endDate);
           ResultSet resultSet = preparedStatement.executeQuery();
           while (resultSet.next()) {
               String regionName = resultSet.getString("name");
               double avgTemperature = resultSet.getDouble("avg_temperature");

               System.out.println("Region: " + regionName);
               System.out.println("Average Temperature: " + avgTemperature);
               System.out.println("------------------------------");
           }
       } catch (SQLException e) {
           e.printStackTrace();
       }
   }
    //Вывести информацию о погоде за прошедшую неделю в регионах, жители которых общаются на заданном языке:
    public static void getWeatherInfoByLanguage(Connection connection, String language) {
        // Предположим, что текущая дата - это конец прошедшей недели
        // Вам может понадобиться уточнить, как определить начало и конец недели в вашей базе данных
        Date endDate = null; // Текущая дата
        Date startDate = null; // Начало недели


        String query = "SELECT w.* " +
                "FROM Weather w " +
                "JOIN Region r ON w.region_id = r.region_id " +
                "WHERE r.language = ? AND w.date BETWEEN ? AND ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, language);
            preparedStatement.setDate(2, startDate);
            preparedStatement.setDate(3, endDate);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                int weatherId = resultSet.getInt("weather_id");
                String weatherDescription = resultSet.getString("description");
                Date date = resultSet.getDate("date");
                double temperature = resultSet.getDouble("temperature");

                System.out.println("Weather ID: " + weatherId);
                System.out.println("Description: " + weatherDescription);
                System.out.println("Date: " + date);
                System.out.println("Temperature: " + temperature);
                System.out.println("------------------------------");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    //Вывести даты, когда в заданном регионе шел снег и температура была ниже заданной отрицательной:
    public static void getSnowDates(Connection connection, String regionName, float maxNegativeTemperature) {
        String query = "SELECT date " +
                "FROM Weather w " +
                "JOIN Region r ON w.region_id = r.region_id " +
                "WHERE r.name = ? AND w.precipitation = 'Snow' AND w.temperature < ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, regionName);
            preparedStatement.setFloat(2, maxNegativeTemperature);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Date date = resultSet.getDate("date");
                System.out.println("Date with Snow and Temperature < " + maxNegativeTemperature + ": " + date);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}