const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
.card{
    max-width: 600px;
     min-height: 400px;
     background: #a9b7d4;
     padding: 30px;
     box-sizing: border-box;
     color: #de0707;
     margin:20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>

<div class="card">
  <h1>ScanGenie</h1><br>
  <h2>Data Value  : <span id="scanValue">0</span></h2><br>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("scanValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readScanData", true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";
