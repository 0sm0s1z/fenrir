def ssh_connect(host, user, key):
   import paramiko
   
   ssh = paramiko.SSHClient()
   ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy()) #auto accept unknown host keys
   
   ssh.connect(host, username=user, key_filename=key)

def ssh_exec(sshAuth, cmd):
   import paramiko
   
   nbytes = 4096
   port = 22

   paramiko.util.log_to_file("support_scripts.log")
   trans = paramiko.Transport((sshAuth['host'],port))
   rsa_key = paramiko.RSAKey.from_private_key_file(sshAuth['key'])
   trans.connect(username=sshAuth['user'], password=sshAuth['pass']) #pkey=rsa_key)
   session = trans.open_session()
   session.exec_command(cmd)
   output = session.makefile('rb', -1).readlines()
   trans.close()
   return output
   
'''
import sys
import paramiko

nbytes = 4096
port = 22
sshAuth = {
"system"   : "iptables",
"host"     : "172.16.0.2",
"user"     : "root",
"pass"     : "",
"key"      : "/Users/0sm0s1z/Sites/fenrir/auth/ssh/id_rsa"
}

port = 22
paramiko.util.log_to_file("support_scripts.log")
trans = paramiko.Transport((sshAuth['host'],port))
rsa_key = paramiko.RSAKey.from_private_key_file(sshAuth['key'])
trans.connect(username=sshAuth['user'], pkey=rsa_key)
session = trans.open_session()
session.exec_command("iptables -L")
output = session.makefile('rb', -1).readlines()
print output
'''



'''

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy()) #auto accept unknown host keys

ssh.connect(sshAuth['host'], username=sshAuth['user'], key_filename=sshAuth['key'])

stdin, stdout, stderr = ssh.exec_command(cmd)
#return stdout.readlines()
ssh.close()




import paramiko

sshAuth = {
"system"   : "iptables",
"host"     : "172.16.0.2",
"user"     : "osm0s1z",
"pass"     : "",
"key"      : "/Users/0sm0s1z/Sites/fenrir/auth/ssh/id_rsa"
}
   
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy()) #auto accept unknown host keys

ssh.connect(sshAuth['host'], username=sshAuth['user'], key_filename=sshAuth['key'])

stdin, stdout, stderr = ssh.exec_command("iptables -vnL")
print stdout.readlines()
ssh.close()
'''
    