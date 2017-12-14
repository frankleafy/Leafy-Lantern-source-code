
  //loaded first
  $("head").append('<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>');
  $("head").append('<script description="helpers.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=1OX9oQYj3ptzk7Os6RF-sqIC-xmKrKo6_"></script>');
  $("head").append('<script description="drawgauge.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=107AU61hsJd6a-KmGqkaPWW_QrPeXdFRp"></script>');


  //document.ready, loaded second
 $(function() 
 {
    //load body template
    $("body").load('http://leafylantern.s3-website.eu-central-1.amazonaws.com/dashboard.html');

    //if adding is needed
    //$.get("http://leafylantern.s3-website.eu-central-1.amazonaws.com/dashboard.html", function (data) {
    //    $("html").append(data);
    //});
 
    console.log( "ready!" );
});

//window.onload (after document.read), loaded third
window.addEventListener("load", function load(event)
{
    window.removeEventListener("load", load, false); //remove listener, no longer needed
    //fill stuff
    drawGauge('#gauges','temp', "getTemp", 5000, 200, 200, 'Temp', 5, 800, 2000, 2000, 3000);
    drawGauge('#gauges','humidity', "getTemp", 2500, 200, 200, 'Humidity', 5, 800, 1000, 1000, 2000); 
},false);

