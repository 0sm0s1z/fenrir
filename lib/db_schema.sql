create table auth_profiles
(
id int NOT NULL AUTO_INCREMENT,
system varchar(255) NOT NULL,
version varchar(255),
alias varchar(255),
host varchar(255) NOT NULL,
user varchar(255) NOT NULL,
pass varchar(255),
authkey varchar(255),
PRIMARY KEY (id)
);

insert into udc_auth_profiles (system, alias, host, username, authkey, version, password)
VALUES("iptables", "EXT-RTR", "172.16.0.2", "root", "auth/ssh/id_rsa", "", "");
insert into udc_auth_profiles (system, alias, host, username, authkey, version, password)
VALUES("iptables", "Nexus", "172.16.0.2", "root", "auth/ssh/id_rsa", "", "");

insert into udc_alerts (severity, sensor, source, destination, signature, time)
VALUES("H", "EXT-RTR", "10.31.33.100", "62.22.1.66", "Malware C2 - Russian Business Network", "2-5-2014");
insert into udc_alerts (severity, sensor, source, destination, signature, time)
VALUES("L", "Nexus", "10.31.33.30", "55.26.97.3", "DNS Exfiltration", "2-5-2014");

insert into udc_rules (alias, sensor, zone, source, destination, protocol, service)
VALUES("EXT-RTR", "iptables", "external", "10.31.33.100", "62.22.1.66", "tcp", "any");

insert into udc_rules (alias, sensor, zone, source, destination, protocol, service)
VALUES("Nexus", "pf", "ptp", "10.31.33.100", "62.22.1.66", "tcp", "any");