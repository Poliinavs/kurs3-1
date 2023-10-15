--  тест  метода REGISTRATION
--SET serveroutput ON;
-- Тестирование функций REGISTRATION и LOGIN
select * from USERS;

------------registration----------------------------

 BEGIN
    AuthPackage.REGISTRATION('user14', 'testee@kmk.com', '1');
    DBMS_OUTPUT.PUT_LINE('Регистрация прошла успешно.');
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка регистрации: ' || SQLERRM);
  END;

  BEGIN
    AuthPackage.REGISTRATION('user14', 'testee@ckmk.com', '1');
    DBMS_OUTPUT.PUT_LINE('Регистрация прошла успешно.');
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка регистрации: ' || SQLERRM);
  END;

    BEGIN
    AuthPackage.REGISTRATION('user143', 'testee@kmk.com', '1');
    DBMS_OUTPUT.PUT_LINE('Регистрация прошла успешно.');
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка регистрации: ' || SQLERRM);
  END;

 BEGIN
    AuthPackage.REGISTRATION('user14dd3', 'testeffekmk.com', '1');
    DBMS_OUTPUT.PUT_LINE('Регистрация прошла успешно.');
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка регистрации: ' || SQLERRM);
  END;

-------------avtorization
 DECLARE
  v_user_id USERS.ID%TYPE;
 BEGIN
 v_user_id := AuthPackage.LOGIN('user1', '10');
 DBMS_OUTPUT.PUT_LINE('Авторизация прошла успешно.ID user: ' || v_user_id);
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка авторизации: ' || SQLERRM);
  END;

  DECLARE
  v_user_id USERS.ID%TYPE;
 BEGIN
 v_user_id := AuthPackage.LOGIN('user1', '1');
 DBMS_OUTPUT.PUT_LINE('Авторизация прошла успешно.ID user: ' || v_user_id);
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Ошибка авторизации: ' || SQLERRM);
  END;





