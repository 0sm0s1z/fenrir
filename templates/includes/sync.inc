<script type="text/javascript">
      //Host: Check & Append
var basealertcount = document.getElementById('currentalertcount').innerHTML;

   
function alertcount()
   {   
            //Count number of hosts
        var newalertcount = 0;
         {% if alerts %}
            {% for alert in alerts %}
              newalertcount++;
            {% endfor %}
        {% endif %}
        
        
        
      if (newalertcount != basealertcount)
      {
            //Number of hosts to append
        var diff = newalertcount - basealertcount;
        var alertid = diff;
        
                
            //Set New HostCount
        document.getElementById('currentalertcount').innerHTML = newalertcount;
        
                  //Get Host Info
         var signature = new Array();
         var severity = new Array();
         var sensor = new Array();
         var source = new Array();
         var destination = new Array();
         var time = new Array();
         var sig_id = new Array();
         var protocol = new Array();
         var application = new Array();
         var catagory = new Array();
         var sport = new Array();
         var dport = new Array();
         var payload =  new Array();
         
         
         {% if alerts %}
          {% for alert in alerts %}
             signature[{{ forloop.counter }}]      = "{{ alert.signature }}";
             severity[{{ forloop.counter }}]       = "{{ alert.severity }}";
             sensor[{{ forloop.counter }}]         = "{{ alert.sensor }}";
             source[{{ forloop.counter }}]         = "{{ alert.source }}";
             destination[{{ forloop.counter }}]    = "{{ alert.destination }}";
             time[{{ forloop.counter }}]           = "{{ alert.time }}";
             sig_id[{{ forloop.counter }}]         = "{{ alert.sensor_sid }}";
             
             if ('{{ alert.protocol }}' == '1') {
                protocol[{{ forloop.counter }}]         = "ICMP";
             }
             else if ('{{ alert.protocol }}' == '6') {
                protocol[{{ forloop.counter }}]         = "TCP";
             }
             else if ('{{ alert.protocol }}' == '17') {
                protocol[{{ forloop.counter }}]         = "UDP";
             }
             else if ('{{ alert.protocol }}' == '58') {
                protocol[{{ forloop.counter }}]         = "ICMPv6";
             }
             
             application[{{ forloop.counter }}]    = "{{ alert.dport }} -> {{ alert.sport }}";
             catagory[{{ forloop.counter }}]           = "{{ alert.signature_class }}";
             payload[{{ forloop.counter }}]           = "{{ alert.payload }}";
             
             
             //payload[{{ forloop.counter }}]           = "";
          {% endfor %}
         {% endif %}
        
            //Append Hosts & CTRLs
        while (diff >  0)
         {
              //Find Host ID
            //var alertid = parseInt(basealertcount) + parseInt(diff);
            //alertid = parseInt(basealertcount)
            //alert(alertid);
            //alert(signature[alertid]);
            
               //Generate HTML
            var alertHTML = "";
            
            var tableObject = document.getElementById("table1");
            var rowCount = tableObject.rows.length;
            
            if (rowCount%2 == 0) {
                rowstyle = "widgetrowa";
            }
            else
            {
                rowstyle = "widgetrowb";
            }
               
               //Small Box
            alertHTML +='  <tr class = "' + rowstyle + '" style = "cursor: pointer;">';
            alertHTML +='      <td><input type="checkbox"></td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '"></td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '"></td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '"></td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '"></td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '">' + signature[alertid] + '</td>';
            alertHTML +='      <td name = "alert' + alertid + '" id = "alert' + alertid + '"></td>';
            alertHTML +='  </tr>';
            alertHTML +='';
       

               //Add new alert
            //document.getElementById('table1').innerHTML += alertHTML;
            //var column1=tableObject.rows[rowCount].insertCell(0);
            //column1.innerHTML= alertHTML;
            row = tableObject.insertRow(1);
            var cell1 = row.insertCell(0);
            var cell2 = row.insertCell(1);
            var cell3 = row.insertCell(2);
            var cell4 = row.insertCell(3);
            var cell5 = row.insertCell(4);
            var cell6 = row.insertCell(5);
            var cell7 = row.insertCell(6);
            var cellname = 'alert' + alertid;
            var expandFunc = 'expandAlert(' + alertid + ');';
            
            
            cell1.innerHTML = '<input type="checkbox">';
            cell1.setAttribute("name", cellname);
            cell1.setAttribute("id", cellname);
            cell1.setAttribute("onclick", expandFunc);
            cell2.innerHTML = severity[alertid];
            cell2.setAttribute("name", cellname);
            cell2.setAttribute("id", cellname);
            cell2.setAttribute("onclick", expandFunc);
            cell3.innerHTML = sensor[alertid];
            cell3.setAttribute("name", cellname);
            cell3.setAttribute("id", cellname);
            cell3.setAttribute("onclick", expandFunc);
            cell4.innerHTML = source[alertid];
            cell4.setAttribute("name", cellname);
            cell4.setAttribute("id", cellname);
            cell4.setAttribute("onclick", expandFunc);
            cell5.innerHTML = destination[alertid];
            cell5.setAttribute("name", cellname);
            cell5.setAttribute("id", cellname);
            cell5.setAttribute("onclick", expandFunc);
            cell6.innerHTML = signature[alertid];
            cell6.setAttribute("name", cellname);
            cell6.setAttribute("id", cellname);
            cell6.setAttribute("onclick", expandFunc);
            cell7.innerHTML = time[alertid];
            cell7.setAttribute("name", cellname);
            cell7.setAttribute("id", cellname);
            cell7.setAttribute("onclick", expandFunc);
            row.className = rowstyle;
            
            var pay = new Array();
            var raw = payload[alertid];
            var line = "0000000";
            try {
               var pay = payload[alertid].match(/.{1,36}/g);
            } catch(e) {
               var i = 1;
            }
            try
            {
               for (var i = 0; i < raw.length / 36; i ++)
               {
                  if (i%2 == 0) {
                     pay[i] += '  ';

                  }
                  else {
                     pay[i] += '\n' + line + ': ';
                  }
               }
            } catch(e) {
               var i = 1;
            }
           

            //alert(payload.length / 16);
            //alert(lines);
            //payload[alertid].match(/.{1,16}/g)
            
            
            //Alert Details
            row = tableObject.insertRow(2);
            var dcell1 = row.insertCell(0);
            row.className = "alert_details";
            row.setAttribute("id", "alert_details" + alertid);
            dcell1.setAttribute("colspan", "7")
            
            var detailsHTML = "";
            
            
            detailsHTML +='<div id = "menu_padding">';
            detailsHTML +='   <div id = "alert_menu">';
            detailsHTML +='      <a href="#" name="addsys" class="menubutton">Follow Event Stream</a>';
            detailsHTML +='      <a href="#" name="addsys" class="menubutton">Alert Classification</a>';
            detailsHTML +='      <a href="#" name="addsys" class="menubutton">Asymptote</a>';
            detailsHTML +='      <a href="#" name="filter_traffic" class="menubutton" onclick = "filter_menu(' + alertid + ')">Filter Traffic</a>';
            detailsHTML +='   </div>';
            detailsHTML +='   <div id = "alert_title">Classification: Active Incident</div>';
            detailsHTML +='   <table border = "0" cellspacing = "0" cellpadding = "0" class = "info_block">';
            detailsHTML +='      <tr class = "info_header">';
            detailsHTML +='         <td>';
            detailsHTML +='            Source';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Destination';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Protocol';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Application';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Timestamp';
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='      <tr>';
            detailsHTML +='         <td>';
            detailsHTML +='            <a href="#" name="addsys" class="menubutton">' + source[alertid] + '</a>';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            <a href="#" name="addsys" class="menubutton">' + destination[alertid] + '</a>';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + protocol[alertid];
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + application[alertid];
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + time[alertid];
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='      <tr class = "info_header">';
            detailsHTML +='         <td>';
            detailsHTML +='            Triggered Sensor';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Triggered Rule';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Catagory';
            detailsHTML +='         </td>';
            detailsHTML +='         <td colspan = "2">';
            detailsHTML +='            References';
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='      <tr>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + sensor[alertid] +': Snort';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            <a href="#" name="addsys" class="menubutton">' + signature[alertid] + '</a>';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + catagory[alertid];
            detailsHTML +='         </td>';
            detailsHTML +='         <td colspan = "2">';
            detailsHTML +='            www.emergingthreatspro.com';
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='   </table>';
            detailsHTML +='   <div id = "alert_title">Signature</div>';
            detailsHTML +='   <table border = "0"cellspacing = "0" cellpadding = "0" class = "info_block">';
            detailsHTML +='      <tr class = "info_header">';
            detailsHTML +='         <td>';
            detailsHTML +='            Type';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Signature ID';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            Incidence';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ';
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='      <tr>';
            detailsHTML +='         <td>';
            detailsHTML +='            Snort: Emerging Threats';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ' + sig_id[alertid];
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            2';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ';
            detailsHTML +='         </td>';
            detailsHTML +='         <td>';
            detailsHTML +='            ';
            detailsHTML +='         </td>';
            detailsHTML +='      </tr>';
            detailsHTML +='   </table>';
            detailsHTML +='   <div id = "alert_title">Payload</div>';
            detailsHTML +='      <div class="alert_payload_box">';
            detailsHTML +='<pre><span class="payload-number">0000000:</span> <span class="payload-hex">' + pay.join('') + '</span> <span class="payload-ascii"></span></pre>';
            detailsHTML +='      </div>';
            detailsHTML +='   <div id = "alert_title">Notes</div>';
            detailsHTML +='      No notes yet!<br /><br />';
            detailsHTML +='      <a href="#" name="addsys" class="menubutton">Add Note</a>';
            detailsHTML +='</div>';
            detailsHTML +='<br>';
            

            dcell1.innerHTML = detailsHTML;
                      
                      
            //Make odd # to allow rowstyles
            row = tableObject.insertRow(3);
               //Hide Expanded box onLoad
	    //$("#expand" + hostid).hide();

       
            diff--;
            alertid--;
         }
      }
   }

   //notificationcheck();
   //hostcount();
   //update();
   alertcount();


</script>