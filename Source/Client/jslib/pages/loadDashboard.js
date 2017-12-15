
  //loaded first
  $("head").append('<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>');
  $("head").append('<script description="helpers.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=1OX9oQYj3ptzk7Os6RF-sqIC-xmKrKo6_"></script>');
  $("head").append('<script description="drawgauge.js" type="text/javascript" src="https://drive.google.com/uc?export=download&id=107AU61hsJd6a-KmGqkaPWW_QrPeXdFRp"></script>');
  $("head").append('<meta charset="utf-8">');
  $("head").append('<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">');
  $("head").append('<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css" integrity="sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb" crossorigin="anonymous">');
  
  $("head").append('<meta name="author" content="Frank Kroondijk">');
  $("head").append('<link rel="icon" href="http://leafylantern.s3-website.eu-central-1.amazonaws.com/favicon.ico">');
  $("head").append('<link rel="shortcut icon" href="http://leafylantern.s3-website.eu-central-1.amazonaws.com/favicon.ico" type="image/x-icon">');
  $("head").append('<link rel="icon" href="http://leafylantern.s3-website.eu-central-1.amazonaws.com/favicon.ico" type="image/x-icon">');

  $("head").append('<title>Leafy Lantern Dashboard</title>');
  $("head").append('<link href="http://leafylantern.s3-website.eu-central-1.amazonaws.com/css/bootstrap.min.css" rel="stylesheet">');
  $("head").append('<link href="http://leafylantern.s3-website.eu-central-1.amazonaws.com/css/jumbotron.css" rel="stylesheet">');


  //document.ready, loaded second
 $(function() 
 {
    //load body template
    $("body").load('http://leafylantern.s3-website.eu-central-1.amazonaws.com/dashboard.html');
    $("body").append('<script src="http://leafylantern.s3-website.eu-central-1.amazonaws.com/js/popper.min.js"></script>');
    $("body").append('<script src="http://leafylantern.s3-website.eu-central-1.amazonaws.com/js/bootstrap.min.js"></script>');

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
    drawGauge('#temp','temp', "getTemp", 5000, 200, 200, 'Temp', 5, 800, 2000, 2000, 3000);
    drawGauge('#humid','humidity', "getTemp", 2500, 200, 200, 'Humidity', 5, 800, 1000, 1000, 2000); 
    drawGauge('#light','light', "getTemp", 3500, 200, 200, 'Light', 5, 800, 1000, 1000, 2000); 
    drawGauge('#water','water', "getTemp", 3500, 200, 200, 'Water', 5, 800, 1000, 1000, 2000); 
},false);

