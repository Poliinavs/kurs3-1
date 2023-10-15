--AUNTIFICATION AND REGISTRATION
select * from USERS;


CREATE OR REPLACE TRIGGER hash_password
BEFORE INSERT ON USERS
FOR EACH ROW
DECLARE
    hashed_password RAW(64); -- RAW(64) для SHA-256
BEGIN
    -- Хэширование пароля с использованием SHA-256
    hashed_password := DBMS_CRYPTO.HASH(UTL_RAW.CAST_TO_RAW(:NEW.PASSWORD), DBMS_CRYPTO.HASH_SH256);

    -- Преобразование хэшированного значения в строку для сохранения в столбце PASSWORD
    :NEW.PASSWORD := RAWTOHEX(hashed_password);
END;



--activate pdb
CREATE OR REPLACE TRIGGER activate_pdb_kursov
AFTER STARTUP ON DATABASE
BEGIN
  EXECUTE IMMEDIATE 'ALTER PLUGGABLE DATABASE kursov OPEN';
END;