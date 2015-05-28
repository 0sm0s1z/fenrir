<script>
jQuery(function($, undefined) {
    $('#terminal_window').terminal(function(command, term) {
      
      $.post("/udc/", {
            cmd:	command,
      });
      
      var count = document.getElementById("term_cont").innerHTML;
      document.getElementById("term_cont").innerHTML += '<a href = "#15"></a><div style="width: 100%;">Connecting to ' + command + '...</div>';
      jump("15")

      
      /*
      if (command == "@nexus")
      {
         alert("gotcha");
      }
      else if (command !== '') {
          y {
              var result = window.eval(command);
              if (result !== undefined) {
                  term.echo(new String(result));
              }
          } catch(e) {
              term.error(new String(e));
          }
      } else {
         term.echo('');
      }
      */
    }, {
        greetings: 'Welcome to the Fenrir -- Unified Defense Console',
        name: 'udc',
        height: 80,
        prompt: 'fenrir> '});
});

function jump(h){
    var url = location.href;               //Save down the URL without hash.
    location.href = "#"+h;                 //Go to the target element.
    history.replaceState(null,null,url);   //Don't like hashes. Changing it back.
}
</script>
   
<script type="text/javascript">
function expandAlert(alertid)
{
    var i = 0;
    if ($("#alert_details" + alertid).is(":visible") == true)
    {
       i = 1; 
    }
    hideAlerts();
    if (i == 0) {
       $("#alert_details" + alertid).show("slow");
    }
}


function hideAlerts()
{
   for (var alertcount = document.getElementById('currentalertcount').innerHTML; alertcount != 0; alertcount--)
   {
      $("#alert_details" + alertcount).hide();
   }
   
   {% if auth_profiles %}
    {% for profile in auth_profiles %}
         $("#{{ profile.id }}rules").hide();
      {% endfor %}
   {% endif %}
}

    
    /*
$(document).ready(function () {
  
        //select all the a tags named startpwn
    $('a[name=newsys]').click(function(e) {
            //Cancel the link behavior
        e.preventDefault();
            //Get the A tag
        var id = $(this).attr('href');
        
        hideConfigMain();
        $("#newsys").show();
        //$(".autogate").fadeOut("slow");
    }); 
});
*/
function hideConfigMain()
{
   $("#config").hide();
   $("#newsys").hide();
    $("#netpol").hide();
    $("#netrules").hide();
   
   {% if auth_profiles %}
    {% for profile in auth_profiles %}
         $("#{{ profile.id }}rules").hide();
      {% endfor %}
   {% endif %}
}
</script>
<script type="text/javascript">
   //Modal Popups
   //New System Wizard
$(document).ready(function () {
   $('a[name=newsys]').click(function(e) {
      var statesdemo = {
         state0: {
            title: '<h2>Add New System</h2>',
            html:
               '<table><tr><td><label class="required" for="id_system">System:</label></td><td><select id = "id_system"><option value = "iptables">iptables</option><option value = "squid">Squid</option><option value = "snort">Snort</option></select></td></tr>'+
               //'<tr><td><label class="required" for="id_version">Version:</label></td><td><input class="vTextField" id="id_version" maxlength="200" name="version" type="text"></td></tr>'+
               '<tr><td><label class="required" for="id_alias">Alias:</label></td><td><input class="vTextField" id="id_alias" maxlength="200" name="alias" type="text"></td></tr>'+
               '<tr><td><label class="required" for="id_host">IP Address:</label></td><td><input class="vTextField" id="id_host" maxlength="200" name="host" type="text"></td></tr>'+
               '<tr><td>&nbsp;</td></tr><tr><td><h4>Authentication Details:</h4></td></tr>'+
               '<tr><td><label class="required" for="id_username">Username:</label></td><td><input class="vTextField" id="id_username" maxlength="200" name="username" type="text"></td></tr>'+
               '<tr><td><label class="required" for="id_password">Password:</label></td><td><input class="vTextField" id="id_password" maxlength="200" name="password" type="password"></td></tr>'+
               //'<tr><td><label class="required" for="id_authkey">Authkey:</label></td><td><input class="vTextField" id="id_authkey" maxlength="200" name="authkey" type="text"></td></tr>'+
               '</table><br>',
            buttons: { Submit: 1 },
            //focus: "input[name='fname']",
            submit:function(e,v,m,f){ 
               console.log(f);
      
               e.preventDefault();
               if (v==1)
               {
                
                  $.post("/addsys/", {
                     system:	   document.getElementById('id_system').value,
                     //version:	   document.getElementById('id_version').value,
                     alias:	   document.getElementById('id_alias').value,
                     host:	      document.getElementById('id_host').value,
                     username:	document.getElementById('id_username').value,
                     password:	document.getElementById('id_password').value
                     //authkey:	   document.getElementById('id_authkey').value
                  });
                  $.prompt.close();
               }
            }
         },
      };
      $.prompt(statesdemo);
   }); 
});
   //New Rule Wizard
$(document).ready(function () {
   $('a[name=newrule]').click(function(e) {
      var statesdemo = {
         state0: {
            title: 'Add New Rule <select id = "g_system">{% if auth_profiles %}{% for profile in auth_profiles %}<option value = "{% if profile.alias %}{{ profile.alias }}{% else %}{{ profile.host }}{% endif %}">{% if profile.alias %}{{ profile.alias }}{% else %}{{ profile.host }}{% endif %}</option>{% endfor %}{% endif %}</select><lable style = "float:right">Enabled <input type = "checkbox">&nbsp;&nbsp;&nbsp;</lable>',
            html:
               '<label>Sensor <select id = "g_sensor"><option value = "iptables">iptables</option><option value = "cisco">cisco</option><option value = "pf">pf</option></select></label><br />'+
               '<div id = "rule_wizard1"><fieldset class = "modal_menu"><legend><h4>General</h4></legend>'+
               '<table><tr><td>Action:</td><td>Allow <input type="radio" name="g_action" id = "g_action" value="allow"> Deny <input type="radio" name="g_action" id="g_action" value="deny"> Drop <input type="radio" name="g_action" id="g_action" value="drop"></td></tr>'+
               '</table>'+
               '</fieldset>'+
               '<fieldset class = "modal_menu"><legend><h4>Source</h4></legend>'+
               '<table><tr><td>Endpoint IP:</td><td><input type="text" name="s_endpoint" id = "s_endpoint" value=""> <td></tr>'+
               '<tr><td>Protocol:</td><td><input type="text" name="s_proto" id = "s_proto" value=""></td></tr>'+
               '<tr><td>Zone:</td><td><select id = "s_zone"><option value ="external">external</option><option value ="internal">internal</option><option value ="dmz">dmz</option></select></td></table>'+
               '</fieldset>'+
               '<fieldset class = "modal_menu"><legend><h4>Destination</h4></legend>'+
               '<table><tr><td>Endpoint IP:</td><td><input type="text" name="d_endpoint" id = "d_endpoint" value=""></td></tr>'+
               '<tr><td>Protocol:</td><td><input type="text" name="d_proto" id = "d_proto" value=""></td></tr>'+
               '<tr><td>Zone:</td><td><select id = "d_zone"><option value ="external">external</option><option value ="internal">internal</option><option value ="dmz">dmz</option></select></td></table>'+
               '</fieldset></div>',
            buttons: { Advanced: 1, Apply: 2 },
            //focus: "input[name='fname']",
            submit:function(e,v,m,f){ 
               console.log(f);
      
               e.preventDefault();
               if (v==2)
               {
                  $.post("/addrule/", {
                     system:	      document.getElementById('g_system').value,
                     sensor:	      document.getElementById('g_sensor').value,
                     action:	      $('input[name="g_action"]:checked').val(),
                     s_endpoint:	   document.getElementById('s_endpoint').value,
                     s_proto:	      document.getElementById('s_proto').value,
                     s_zone:	      document.getElementById('s_zone').value,
                     d_endpoint:	   document.getElementById('d_endpoint').value,
                     d_proto:	      document.getElementById('d_proto').value,
                     d_zone:	      document.getElementById('d_zone').value
                  });
                  $.prompt.close();
               }
               if(v==1) $.prompt.goToState('state1');
            }
         },
         state1: {
            title: 'Gender',
            html:'<label><input type="radio" name="gender" value="Male"> Male</label><br />'+
               '<label><input type="radio" name="gender" value="Female"> Female</label>',
            buttons: { Back: -1, Next: 1 },
            //focus: ":input:first",
            submit:function(e,v,m,f){ 
               console.log(f);
      
               if(v==1) $.prompt.goToState('state2')
               if(v==-1) $.prompt.goToState('state0');
               e.preventDefault();
            }
         },
         state2: {
            title: 'Transportation',
            html:'<label>Travels By <select name="travel" multiple>'+
                  '<option value="Car" selected>Car</option>'+
                  '<option value="Bus">Bus</option>'+
                  '<option value="Plane" selected>Plane</option>'+
                  '<option value="Train">Train</option>'+
               '</select></label>',
            buttons: { Back: -1, Done: 1 },
            focus: 1,
            submit:function(e,v,m,f){ 
               console.log(f);
      
               e.preventDefault();
               if(v==1) $.prompt.close();
               if(v==-1) $.prompt.goToState('state1');
            }
         },
      };
      
      $.prompt(statesdemo);
   }); 
});




//Filter Wizard
function filter_menu(id)
{
    var statesdemo = {
        state0: {
           title: 'Filter Traffic <select id = "g_system">{% if auth_profiles %}{% for profile in auth_profiles %}<option value = "{% if profile.alias %}{{ profile.alias }}{% else %}{{ profile.host }}{% endif %}">{% if profile.alias %}{{ profile.alias }}{% else %}{{ profile.host }}{% endif %}</option>{% endfor %}{% endif %}</select>',
           html:
              '<label>Sensor <select id = "g_sensor"><option value = "iptables">iptables</option><option value = "iptables">squid</option><option value = "cisco">cisco</option><option value = "pf">pf</option></select></label><br />'+
              '<label>Method <select id = "g_sensor"><option value = "iptables">ip</option><option value = "iptables">snort rule</option><option value = "cisco">signature</option><option value = "pf">geography</option></select></label><br /><br />'+
              '<div id = "filter_ip">'+
              '<fieldset class = "modal_menu"><legend><h4>Composite Filter</h4></legend>'+
              '<table><tr><td>Filter Type:</td><td>IP</td></tr>'+
              '<tr><td>Traffic Signature:</td><td>deny udp 10.31.33.30 to 55.26.97.3 protocol = dns</td></tr>'+
              '<tr><td>Zone:</td><td><select id = "d_zone"><option value ="external">external</option><option value ="internal">internal</option><option value ="dmz">dmz</option></select></td></table>'+
              '</fieldset></div>',
           buttons: { Advanced: 1, Apply: 2 },
           //focus: "input[name='fname']",
           submit:function(e,v,m,f){ 
              console.log(f);
     
              e.preventDefault();
              if (v==2)
              {
                /*
                 $.post("/filter/", {
                    system:	      document.getElementById('g_system').value,
                    sensor:	      document.getElementById('g_sensor').value,
                    action:	      $('input[name="g_action"]:checked').val(),
                    s_endpoint:	   document.getElementById('s_endpoint').value,
                    s_proto:	      document.getElementById('s_proto').value,
                    s_zone:	      document.getElementById('s_zone').value,
                    d_endpoint:	   document.getElementById('d_endpoint').value,
                    d_proto:	      document.getElementById('d_proto').value,
                    d_zone:	      document.getElementById('d_zone').value
                 });
                */
                 $.prompt.close();
              }
              if(v==1) $.prompt.goToState('state1');
           }
        },
        state1: {
           title: 'Gender',
           html:'<label><input type="radio" name="gender" value="Male"> Male</label><br />'+
              '<label><input type="radio" name="gender" value="Female"> Female</label>',
           buttons: { Back: -1, Next: 1 },
           //focus: ":input:first",
           submit:function(e,v,m,f){ 
              console.log(f);
     
              if(v==1) $.prompt.goToState('state2')
              if(v==-1) $.prompt.goToState('state0');
              e.preventDefault();
           }
        },
        state2: {
           title: 'Transportation',
           html:'<label>Travels By <select name="travel" multiple>'+
                 '<option value="Car" selected>Car</option>'+
                 '<option value="Bus">Bus</option>'+
                 '<option value="Plane" selected>Plane</option>'+
                 '<option value="Train">Train</option>'+
              '</select></label>',
           buttons: { Back: -1, Done: 1 },
           focus: 1,
           submit:function(e,v,m,f){ 
              console.log(f);
     
              e.preventDefault();
              if(v==1) $.prompt.close();
              if(v==-1) $.prompt.goToState('state1');
           }
        },
    };
    $.prompt(statesdemo);
    
    //alert(id);
}
</script>