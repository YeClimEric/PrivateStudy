create database company; #创建数据库

use company;#使用数据库

#创建一个表
create table t_dept(
	deptno INT,
    dname varchar(20),
    loc varchar(40)
); 

#展开表的描述，可用desc
describe t_dept;
#删除表
drop table t_dept;
drop table t_dept2;
#修改表名 
alter table t_dept rename t_dept2;

describe t_dept2;

desc t_dept2;

#给现存表新增字段
alter table t_dept2 add descri varchar(20);

#在表的第一个位置新增字段
alter table t_dept2 add description varchar(20) first;

alter table t_dept2 add external int after dname;
#删除表内字段
alter table t_dept2 drop external;
#修改字段的数据类型
alter table t_dept2 modify deptno varchar(20);
#修改字段名字alter
alter table t_dept2 change loc location varchar(20);
alter table t_dept2 change location loc int;

desc t_dept2;
#调整字段顺序
alter table t_dept2 modify deptno int after dname;
alter table t_dept2 modify deptno varchar(20) first;

#设置非空约束
create table t_dept(
	deptno int(20) not null,
    dname varchar(20),
    location varchar(20)
);
desc t_dept;
alter table t_dept add val varchar(20) default "aaa";
alter table t_dept modify dname varchar(20) default "name";
alter table t_dept modify deptno int(20) unique;
alter table t_dept modify deptno int(20) primary key;

alter table t_dept2 add constraint fk_deptno foreign key(deptno) references t_dept(deptno);