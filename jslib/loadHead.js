

  
  $("head").append('<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>');
  $("head").append('<script description="helpers.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=1OX9oQYj3ptzk7Os6RF-sqIC-xmKrKo6_"></script>');
  $("head").append('<script description="drawgauge.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=107AU61hsJd6a-KmGqkaPWW_QrPeXdFRp"></script>');

 $(function() 
 {
    //create body
    $("body").append('<p/>&nbsp;<p/>&nbsp;<p/>&nbsp;<p/>');
    $("body").append('<div id=\"gauges\" width=\"100%\"></div>');
    console.log( "ready!" );
});

window.onload = function () 
{
    //fill body with js functions

    //sName,  sCall, timer, gWidth, gHeight, sLabel, iminorTicks, iyellowFrom, iyellowTo, iredFrom, iredTo
    drawGauge('#gauges','temp', "getTemp", 5000, 200, 200, 'Temp', 5, 800, 2000, 2000, 3000);
    drawGauge('#gauges','humidity', "getTemp", 2500, 200, 200, 'Humidity', 5, 800, 1000, 1000, 2000); 
};