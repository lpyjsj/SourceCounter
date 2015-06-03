[主页](BingBookCN.md) - [设计文档](BingBookSpec.md)

## 导入格式 ##

|last\_name|first\_name|business\_phone|business\_mobile|home\_phone|home\_mobile|email|
|:---------|:----------|:--------------|:---------------|:----------|:-----------|:----|
|周       |星驰     |010-12345678   |13900008888     |010-43215678|13300009999 |xingchi.zhou@gmail.com|

  * 导入模板下载
    * [http://boomworks.googlecode.com/files/BingBookImportFmt\_V2.xls](http://boomworks.googlecode.com/files/BingBookImportFmt_V2.xls)

  * 注意
    * 使用.xls 文件进行导入的时候，请保留第一行的英文字段。
    * 导入的时候，目前不会对同名联系人进行检查。
    * 建议使用\*Excel软件\*来编辑 .xls 文件。
    * 除了last\_name 和 first\_name 其他的字段可以为空（什么也不填）。

## 关于字段名 ##

| **字段名** | **字段长度** | **中文名** |
|:--------------|:-----------------|:--------------|
|id             |INTEGER           |ID             |
|last\_name     |VARCHAR(32)       |姓            |
|last\_name\_alpha|VARCHAR(32)       |姓拼音      |
|first\_name    |VARCHAR(32)       |名            |
|first\_name\_alpha|VARCHAR(32)       |名拼音      |
|sex            |INTEGER           |性别         |
|birthday       |TIMESTAMP         |生日         |
|company        |VARCHAR(128)      |公司         |
|department     |VARCHAR(64)       |部门         |
|job\_title     |VARCHAR(64)       |职务         |
|business\_fax  |VARCHAR(16)       |办公传真(1)|
|business\_fax\_2|VARCHAR(16)       |办公传真(2)|
|business\_phone|VARCHAR(16)       |办公电话(1)|
|business\_phone\_2|VARCHAR(16)       |办公电话(2)|
|business\_mobile|VARCHAR(16)       |办公手机(1)|
|business\_mobile\_2|VARCHAR(16)       |办公手机(2)|
|business\_street|VARCHAR(256)      |办公住址(1)|
|business\_street\_2|VARCHAR(256)      |办公住址(2)|
|business\_street\_3|VARCHAR(256)      |办公住址(3)|
|home\_fax      |VARCHAR(16)       |住宅传真(1)|
|home\_fax\_2   |VARCHAR(16)       |住宅传真(2)|
|home\_phone    |VARCHAR(16)       |住宅电话(1)|
|home\_phone\_2 |VARCHAR(16)       |住宅电话(2)|
|home\_mobile   |VARCHAR(16)       |个人手机(1)|
|home\_mobile\_2|VARCHAR(16)       |个人手机(2)|
|home\_street   |VARCHAR(256)      |家庭住址(1)|
|home\_street\_2|VARCHAR(256)      |家庭住址(2)|
|home\_street\_3|VARCHAR(256)      |家庭住址(3)|
|email          |VARCHAR(32)       |电子邮件(1)|
|email\_2       |VARCHAR(32)       |电子邮件(2)|
|webpage        |VARCHAR(64)       |网页(1)      |
|webpage\_2     |VARCHAR(64)       |网页(2)      |
|comment        |VARCHAR(512)      |备考         |
|latest\_update\_time|TIMESTAMP DEFAULT CURRENT\_TIMESTAMP NULL,|最终更新时间|
|latest\_update\_user\_id|INTEGER           |最终更新者ID|
|entry\_time    |TIMESTAMP DEFAULT CURRENT\_TIMESTAMP NULL,|录入时间   |
|entry\_user\_id|INTEGER           |录入者ID    |
|business\_im   |VARCHAR(32)       |办公即时通信工具(1)|
|business\_im\_2|VARCHAR(32)       |办公即时通信工具(2)|
|business\_im\_3|VARCHAR(32)       |办公即时通信工具(3)|
|home\_im       |VARCHAR(32)       |私用即时通信工具(1)|
|home\_im\_2    |VARCHAR(32)       |私用即时通信工具(2)|
|home\_im\_3    |VARCHAR(32)       |私用即时通信工具(3)|

### 参考 ###

- 数据库表定义

```

CREATE TABLE [contacts] (
[id] INTEGER  PRIMARY KEY NULL,
[last_name] VARCHAR(32)  NOT NULL,
[last_name_alpha] VARCHAR(32)  NOT NULL,
[first_name] VARCHAR(32)  NOT NULL,
[first_name_alpha] VARCHAR(32)  NOT NULL,
[sex] INTEGER  NOT NULL,
[birthday] TIMESTAMP  NULL,
[company] VARCHAR(128)  NULL,
[department] VARCHAR(64)  NULL,
[job_title] VARCHAR(64)  NULL,
[business_fax] VARCHAR(16)  NULL,
[business_fax_2] VARCHAR(16)  NULL,
[business_phone] VARCHAR(16)  NULL,
[business_phone_2] VARCHAR(16)  NULL,
[business_mobile] VARCHAR(16)  NULL,
[business_mobile_2] VARCHAR(16)  NULL,
[business_street] VARCHAR(256)  NULL,
[business_street_2] VARCHAR(256)  NULL,
[business_street_3] VARCHAR(256)  NULL,
[home_fax] VARCHAR(16)  NULL,
[home_fax_2] VARCHAR(16)  NULL,
[home_phone] VARCHAR(16)  NULL,
[home_phone_2] VARCHAR(16)  NULL,
[home_mobile] VARCHAR(16)  NULL,
[home_mobile_2] VARCHAR(16)  NULL,
[home_street] VARCHAR(256)  NULL,
[home_street_2] VARCHAR(256)  NULL,
[home_street_3] VARCHAR(256)  NULL,
[email] VARCHAR(32)  NULL,
[email_2] VARCHAR(32)  NULL,
[webpage] VARCHAR(64)  NULL,
[webpage_2] VARCHAR(64)  NULL,
[comment] VARCHAR(512)  NULL,
[latest_update_time] TIMESTAMP DEFAULT CURRENT_TIMESTAMP NULL,
[latest_update_user_id] INTEGER  NULL,
[entry_time] TIMESTAMP DEFAULT CURRENT_TIMESTAMP NULL,
[entry_user_id] INTEGER  NULL,
[business_im] VARCHAR(32)  NULL,
[business_im_2] VARCHAR(32)  NULL,
[business_im_3] VARCHAR(32)  NULL,
[home_im] VARCHAR(32)  NULL,
[home_im_2] VARCHAR(32)  NULL,
[home_im_3] VARCHAR(32)  NULL
);

```

- 全部的字段名

```
last_name,last_name_alpha,first_name,first_name_alpha,sex,birthday,company,department,job_title,business_fax,business_fax_2,business_phone,business_phone_2,business_mobile,business_mobile_2,business_street,business_street_2,business_street_3,home_fax,home_fax_2,home_phone,home_phone_2,home_mobile,home_mobile_2,home_street,home_street_2,home_street_3,email,email_2,webpage,webpage_2,comment,latest_update_time,latest_update_user_id,entry_time,entry_user_id,business_im,business_im_2business_im_3,home_im,home_im_2,home_im_3
```