------ ������� ������� ------
--1. select � ������ �������� (1 ������!)
    declare
        fac faculty%rowtype;
    begin
        select * into fac from faculty where faculty='���';
        dbms_output.put_line(fac.faculty||' '||fac.faculty_name);
    end;
    
--2-4. select � �������� �������� + When others
    declare
        fac faculty%rowtype;
    begin
        --select * into fac from faculty;     --���-�� ����� > ������
        select * into fac from faculty where faculty='XXX';
    exception
        when no_data_found
        then dbms_output.put_line('������ �� �������');
        when too_many_rows
        then dbms_output.put_line('� ���������� ��������� �����');
        when others
        then dbms_output.put_line(sqlerrm);
    end;


select * from auditorium;
--5-10. �������� UPDATE + commit/rollback + ����
    begin
        update auditorium set auditorium = '207-1' where auditorium = '206-1';
        --insert into auditorium values ('301-9', '301-1', 90, '��');
        --delete from auditorium where auditorium = '301-8';
        --rollback;
        if sql%found then dbms_output.put('found '); end if;
        if sql%isopen then dbms_output.put('opened '); end if;
        if sql%notfound then dbms_output.put('not found '); end if;
        dbms_output.put_line('���������� �������� '||sql%rowcount);
    exception
        when others then dbms_output.put_line('error = '||sqlerrm);
    end;
    
    ------------------------------
     declare
        sub auditorium%rowtype;
     begin
        update auditorium set auditorium_capacity='Z' where auditorium='301-1';
        --insert into auditorium values ('x', 'x', 'x', 'x');
        --delete from auditorium where auditorium_capacity='x';
        select * into sub from auditorium where auditorium_name='301-1';
    exception
        when others then dbms_output.put_line(sqlerrm);
    end;

---------------- ����� ������� ---------------------
select * from TEACHER;

--11. ������ TEACHER � �������� LOOP-����� + ���� �-� � %TYPE
    declare
        cursor cur is select teacher_name, pulpit, salary from TEACHER;
        m_name      teacher.teacher_name%type;
        m_pulpit    teacher.pulpit%type;
        m_salary    teacher.salary%type;
    begin
        open cur;
        dbms_output.put_line('rowcount = '||cur%rowcount);
        loop
            fetch cur into m_name, m_pulpit, m_salary;
            exit when cur%notfound;
            dbms_output.put_line(cur%rowcount||' '||m_name||' '||
                                 m_pulpit||' '|| m_salary);
        end loop;
        dbms_output.put_line('rowcount = '||cur%rowcount);
        close cur;
    exception
        when others then dbms_output.put_line(sqlerrm);
    end;


select * from subject;
--12. ������ SUBJECT � �������� while-����� + ���� �-� � RECORD(%ROWTYPE)
    declare
        cursor cur is select subject, subject_name, pulpit from SUBJECT;
        rec subject%rowtype;
    begin
        open cur;
        dbms_output.put_line('rowcount = '||cur%rowcount);
        fetch cur into rec;
        while cur%found
            loop
            dbms_output.put_line(cur%rowcount||' '||rec.subject||' '||
                                 rec.subject_name||' '||rec.pulpit);
            fetch cur into rec;
            end loop;
        dbms_output.put_line('rowcount = '||cur%rowcount);
        close cur;
    end;


--13. ���� ��� ������� (PULPIT) � ������� (TEACHER) � JOIN + ������ + for
    declare
        cursor cur
            is select pulpit.pulpit, teacher.teacher_name
            from pulpit inner join teacher on pulpit.pulpit=teacher.pulpit;
        rec cur%rowtype;
    begin
        for rec in cur
        loop
            dbms_output.put_line(cur%rowcount||' '||rec.teacher_name||' '||rec.pulpit);
        end loop;
    end;


--14. ���� ��� ��� � ������������ <20, 21-30, 31-60, 61-80, >81
    declare 
      cursor cur(cap1 auditorium.auditorium%type,cap2 auditorium.auditorium%type)
        is select auditorium, auditorium_capacity
          from auditorium
          where auditorium_capacity >=cap1 and AUDITORIUM_CAPACITY <= cap2;
    begin
      dbms_output.put_line('����������� <20 :');
      for aum in cur(0,20)
      loop dbms_output.put(aum.auditorium||' '); end loop;   
      dbms_output.put_line(chr(10)||'����������� 20-30 :');
      for aum in cur(21,30)
      loop dbms_output.put(aum.auditorium||' '); end loop;    
       dbms_output.put_line(chr(10)||'����������� 30-60 :');
      for aum in cur(31,60)
      loop dbms_output.put(aum.auditorium||' '); end loop;   
       dbms_output.put_line(chr(10)||'����������� 60-80 :');
      for aum in cur(61,80)
      loop dbms_output.put(aum.auditorium||' '); end loop;  
       dbms_output.put_line(chr(10)||'����������� ���� 80 :');
      for aum in cur(81,1000)
      loop dbms_output.put(aum.auditorium||' '); end loop;  
    end;


--15. ������.��� refcursor
    variable x refcursor;
    declare 
      type teacher_name is ref cursor return teacher%rowtype;
      xcurs teacher_name;
    begin
      open xcurs for select * from teacher;
      :x :=xcurs;
    end;
    
    print x;
 
  
--16. ��������� ���������
    declare 
        cursor curs_aut is select auditorium_type,
              cursor (select auditorium from auditorium aum
                      where aut.auditorium_type = aum.auditorium_type)
                      from auditorium_type aut;
        curs_aum sys_refcursor;
        aut auditorium_type.auditorium_type%type;
        aum auditorium.auditorium%type;
    begin
      open curs_aut;
      fetch curs_aut into aut, curs_aum;
      while(curs_aut%found)
      loop
        loop
          fetch curs_aum into aum;
          exit when curs_aum%notfound;
        end loop;
        dbms_output.new_line;
        fetch curs_aut into aut, curs_aum;
      end loop;
      close curs_aut;
    end;


--17. ������ ����������� 40-18 �� 10%
    declare 
      cursor cur(cap1 auditorium.auditorium%type, cap2 auditorium.auditorium%type)
            is select auditorium, auditorium_capacity from auditorium
            where auditorium_capacity between cap1 and cap2 for update;
      aum auditorium.auditorium%type;
      cap auditorium.auditorium_capacity%type;
    begin
      open cur(40,80);
      fetch cur into aum, cap;
      while(cur%found)
      loop
          cap := cap * 0.9;
          update auditorium
          set auditorium_capacity = cap
          where current of cur;
          dbms_output.put_line(' '||aum||' '||cap);
          fetch cur into aum, cap;
      end loop;
      close cur; rollback;
   end;


--18. ������� ��� ��� cap<20
    declare 
      cursor cur(cap1 auditorium.auditorium%type,cap2 auditorium.auditorium%type)
            is select auditorium, auditorium_capacity from auditorium
            where auditorium_capacity between cap1 and cap2 for update;
      aum auditorium.auditorium%type;
      cap auditorium.auditorium_capacity%type;
    begin
      open cur(0,20);
      fetch cur into aum, cap;
      while(cur%found)
      loop
          delete auditorium where current of cur;
          fetch cur into aum, cap;
      end loop;
      close cur;
      
      for pp in cur(0,120) loop
        dbms_output.put_line(pp.auditorium||' '||pp.auditorium_capacity);
      end loop; rollback;
    end;


--19. ���������� ������������� ROWID � update, delete
    declare
    cursor cur(capacity auditorium.auditorium%type)
            is select auditorium, auditorium_capacity, rowid
            from auditorium
            where auditorium_capacity >=capacity for update;
      aum auditorium.auditorium%type;
      cap auditorium.auditorium_capacity%type;
    begin
      for xxx in cur(80)
      loop
        if xxx.auditorium_capacity >=80
          then update auditorium
          set auditorium_capacity = auditorium_capacity+3
          where rowid = xxx.rowid;
        end if;
      end loop;
      for yyy in cur(80)
      loop
        dbms_output.put_line(yyy.auditorium||' '||yyy.auditorium_capacity);
      end loop; rollback;
   end;
  select * from auditorium;
  
  
--20. ��� �������, �������� �� 3 ������
    declare 
      cursor curs_teacher is select teacher, teacher_name, pulpit
          from teacher;
      m_teacher teacher.teacher%type;
      m_teacher_name teacher.teacher_name%type;
      m_pulpit teacher.pulpit%type;
      k integer :=1;
    begin
    open curs_teacher;
    loop
    fetch curs_teacher into m_teacher, m_teacher_name, m_pulpit;
    exit when curs_teacher%notfound;
    DBMS_OUTPUT.PUT_LINE(' '||curs_teacher%rowcount||' '
                          ||m_teacher||' '
                          ||m_teacher_name||' '
                          ||m_pulpit);
    if (k mod 3 = 0) then DBMS_OUTPUT.PUT_LINE('-------------------------------------------'); end if;
    k:=k+1;
    end loop;
     DBMS_OUTPUT.PUT_LINE('rowcount = '|| curs_teacher%rowcount);
     close curs_teacher;
    exception
    when others
    then  DBMS_OUTPUT.PUT_LINE(sqlerrm);
    end;
