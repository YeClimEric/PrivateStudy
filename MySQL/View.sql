#基本语法 
# create view view_name as 查询语句
use company;

CREATE TABLE t_product (
    id INT PRIMARY KEY,
    name VARCHAR(128),
    price DOUBLE
);

drop table t_product;
desc t_product;

insert into t_product(id, name,price) values(1,"apple", 6.5);
insert into t_product(id, name,price) values(2,"banana", 4.5);
insert into t_product(id, name,price) values(3,"orange", 1.5);
insert into t_product(id, name,price) values(4,"peer", 2.5);

explain select * from t_product;

SELECT 
    *
FROM
    t_product;
    

CREATE VIEW view_selectproduct AS
    SELECT 
        id, name
    FROM
        t_product;
        
SELECT 
    *
FROM
    view_selectproduct;

