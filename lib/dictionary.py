#iptables display config
#iptables -t nat -vnL --line-numbers

#Accepted drop commands
def formatcmd(system, cmd):
   if system == "iptables":
      cmd = iptables(cmd)
      return cmd
   
def iptables(cmd):
   if ' '.join(cmd).startswith("drop"):
      lhost = cmd[1]
      newcmd = "iptables -A INPUT -s " + lhost + " -j DROP"
      return newcmd
   elif ' '.join(cmd).startswith("reject"):
      lhost = cmd[1]
      newcmd = "iptables -A INPUT -s " + lhost + " -j DROP"
      return newcmd
      
   elif ' '.join(cmd).startswith("permit"):
      lhost = cmd[1]
      newcmd = "iptables -A INPUT -s " + lhost + " -j DROP"
      return newcmd