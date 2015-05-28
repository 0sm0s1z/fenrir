<script type="text/javascript">

</script>
<div id = "config">
   <div>
      <!-- Alert Counter -->
      <script>
         var alertcount = 0;

         function setbasealertcount(){
            document.getElementById('currentalertcount').innerHTML = alertcount;
         }
               //Set/Hide BaseHostcount
         $(document).ready(function() {  
            $("#currentalertcount").hide();
            setbasealertcount();
         });  
      </script>

      
      <table border = "0"cellspacing = "0" cellpadding = "0" id = "table1" class="widget_list">
      <tr class = "widget_bar">
      <td><input type="checkbox"></td>
      <td>S</td>
      <td>Sensor</td>
      <td>Source</td>
      <td>Destination</td>
      <td>Signature</td>
      <td>Time</td>
      
      </tr>

      </table>
   </div>
</div>

<div id = "currentalertcount">
   0
</div>
