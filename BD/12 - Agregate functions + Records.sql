--SET serveroutput ON;
--alter session set nls_date_format = 'DD-MM-YYYY';

--1. ����� � TEACHER ������� BIRTHDAY, SALARY + ������
    select * from teacher;


--2. ������ �������� � ���� ������� �.�.
    select teacher_name from TEACHER;
    select regexp_substr(teacher_name,'(\S+)',1, 1)||' '||
      substr(regexp_substr(teacher_name,'(\S+)',1, 2),1, 1)||'. '||
      substr(regexp_substr(teacher_name,'(\S+)',1, 3),1, 1)||'. '
    from teacher;


--3. ������ �������� � �� � ��
    select * from teacher
    where TO_CHAR((birthday), 'd') = 2;


--4. ������: ������ �������� � �� � ����. ������
    create view NextMonthBirth as
    select * from teacher
    where TO_CHAR(sysdate,'mm')+1 = TO_CHAR(birthday, 'mm');
    
    select * from NextMonthBirth;
    --drop view NextMonthBirth;


--5. ������: ���-�� �������� � �� � ������ ������
     create view NumberMonths as
     select to_char(birthday, 'Month') �����,
            count(*) ����������
            from teacher
            group by to_char(birthday, 'Month')
            having count(*)>=1;
     
    select * from NumberMonths;
    --drop view NumberTeachersMonths;


--6. ������: ����� �������� � ������� � ����. ����
    cursor TeacherBirtday(teacher%rowtype) 
        return teacher%rowtype is
        select * from teacher
        where MOD((TO_CHAR(sysdate,'yyyy') - TO_CHAR(birthday, 'yyyy')+1), 10)=0;
    

--7. ������: ����� ��.�/� �� �������� � ������.����
    cursor tAvgSalary(teacher.salary%type,teacher.pulpit%type) 
      return teacher.salary%type,teacher.pulpit%type  is
        select floor(avg(salary)), pulpit
        from teacher
        group by pulpit;
  
--���� �������� ��� �. ���������� 
    select round(AVG(T.salary),3),P.faculty
    from teacher T
    inner join pulpit P
    on T.pulpit = P.pulpit
    group by P.faculty
    union
      select floor(avg(salary)), teacher.pulpit
        from teacher
        group by teacher.pulpit
    order by faculty;

-- ��� ���� ����������� � �����
    select round(avg(salary),3) from teacher;


--8. ������ ��� ������ (record) + ���� ������
--��������� �-� ��� ������� �� �����
    declare
        type ADDRESS is record
        (
          town nvarchar2(20),
          country nvarchar2(20)
        );
        type PERSON is record
        (
          name teacher.teacher_name%type,
          pulp teacher.pulpit%type,
          homeAddress ADDRESS
        );
      per1 PERSON;
      per2 PERSON;
    begin
      select teacher_name, pulpit into per1.name, per1.PULP
      from teacher
      where teacher='���';
      per1.homeAddress.town := '�����';
      per1.homeAddress.country := '��������';
      per2 := per1;
      dbms_output.put_line( per2.name||' '|| per2.pulp||' �� '||
                            per2.homeAddress.town||', '|| per2.homeAddress.country);
    end;
    
    
        