package com.example.vetclin.Repozitor;

import com.example.vetclin.model.User;
import org.springframework.jdbc.core.SqlOutParameter;
import org.springframework.jdbc.core.SqlParameter;
import org.springframework.jdbc.core.namedparam.MapSqlParameterSource;
import org.springframework.jdbc.core.namedparam.SqlParameterSource;
import org.springframework.jdbc.core.simple.SimpleJdbcCall;
import org.springframework.stereotype.Repository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;

import java.sql.Types;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Repository
public class UserRepository {
    private static JdbcTemplate jdbcTemplate;

    @Autowired
    public UserRepository(JdbcTemplate jdbcTemplate) {
        UserRepository.jdbcTemplate = jdbcTemplate;
    }

    public static JdbcTemplate getJdbcTemplate() {
        return jdbcTemplate;
    }

    public List<User> getAllUsers() {
        String sql = "SELECT * FROM USERS";
        return jdbcTemplate.query(sql, (resultSet, rowNum) -> {
            User user = new User();
            user.setId(resultSet.getInt("ID"));
            user.setLogin(resultSet.getString("LOGIN"));
            user.setPassword(resultSet.getString("PASSWORD"));
            user.setEmail(resultSet.getString("EMAIL"));
            return user;
        });
    }


    public String callAuthPackageProcedure(String procedureName, Map<String, Object> inParams) {
        SimpleJdbcCall jdbcCall = new SimpleJdbcCall(jdbcTemplate)
                .withProcedureName(procedureName)
                .withCatalogName("AUTHPACKAGE"); // Указываем имя каталога (пакета)

        jdbcCall.declareParameters(
                new SqlParameter("LOGIN_P", Types.VARCHAR),
                new SqlParameter("EMAIL_P", Types.VARCHAR),
                new SqlParameter("PASS_P", Types.VARCHAR),
                new SqlOutParameter("ERROR_CODE", Types.INTEGER),
                new SqlOutParameter("ERROR_MESSAGE", Types.VARCHAR)
        );

        Map<String, Object> outParams = jdbcCall.execute(inParams);


        if (outParams.containsKey("ERROR_CODE")) {
            System.err.println("Произошла ошибка при выполнении процедуры: " + outParams.get("ERROR_MESSAGE"));
        } else {
            System.out.println("Процедура выполнена успешно.");
        }

        return (String) outParams.get("ERROR_MESSAGE");
    }

    public int callLoginFunction(String userLogin, String userPass) {
        SimpleJdbcCall jdbcCall = new SimpleJdbcCall(jdbcTemplate)
                .withFunctionName("LOGIN")
                .withCatalogName("AUTHPACKAGE");

        jdbcCall.declareParameters(
                new SqlParameter("USER_LOGIN", Types.VARCHAR),
                new SqlParameter("USER_PASS", Types.VARCHAR),
                new SqlOutParameter("ERROR_CODE", Types.INTEGER),
                new SqlOutParameter("ERROR_MESSAGE", Types.VARCHAR)
        );

        SqlParameterSource inParams = new MapSqlParameterSource()
                .addValue("USER_LOGIN", userLogin)
                .addValue("USER_PASS", userPass);

        Map<String, Object> outParams = jdbcCall.execute(inParams);
        Integer userId = (Integer) outParams.get("RETURN_VALUE");
        Integer userIds = (Integer) outParams.get("RETURN_VALUE");

        if (outParams != null && outParams.containsKey("RETURN_VALUE")) {
            return (int) outParams.get("RETURN_VALUE");
        } else {
            // Обработка ошибки, если функция не вернула ожидаемое значение
            return -1; // Вернуть значение по умолчанию или код ошибки
        }
    }





}
