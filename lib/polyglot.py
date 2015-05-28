def lexicon(lex):
   command = "Error: The lexicon was unable to conduct sensor translation"
   if lex["sensor"] == "iptables":
      command = iptables(lex)
      
   return command
      
def iptables(cmd):
   
   base = "iptables -A INPUT -s "
   
   if cmd["action"] == "allow":
      pass
   elif cmd["action"] == "drop":
      pass
   elif cmd["action"] == "deny":
      pass
   
   
   
   '''
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
   '''
   
   newcmd = base + cmd["s_endpoint"] + " -d " + cmd["d_endpoint"] + " -p " + cmd["s_proto"].split(":")[0] + " --sport " + cmd["s_proto"].split(":")[1] + " --dport " + cmd["d_proto"].split(":")[1] + " -j " + cmd["action"].upper()
   return newcmd