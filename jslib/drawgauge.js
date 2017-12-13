

function drawGauge(sTarget, sName, sCall, timer, gWidth, gHeight, sLabel, iminorTicks, iyellowFrom, iyellowTo, iredFrom, iredTo)
{
      //"{0} is dead, but {1} is alive! {0} {2}".format("ASP", "ASP.NET")
      var divString = '<div id=\"{2}\" style=\"float: left; width: {0}px; height: {1}px;\"></div>';
      //$(divString.format(gWidth,gHeight,sName)).appendTo('body');
      $(sTarget).append(divString.format(gWidth,gHeight,sName));
      google.charts.load('current', {'packages':['gauge']});
      google.charts.setOnLoadCallback(drawChart);
      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          [sLabel, 0]
        ]);
        var options = {
          min: 0, max: iredTo,
          width: gWidth, height: gHeight,
          redFrom: iredFrom, redTo: iredTo,
          yellowFrom:iyellowFrom, yellowTo: iyellowTo,
          minorTicks: iminorTicks
        };

        var chart = new google.visualization.Gauge(document.getElementById(sName));
        chart.draw(data, options);
        setInterval(function() {
        $.get(sCall, function(getdata, status){
            data.setValue(0, 1, Number(getdata));
            chart.draw(data, options);
        });
        }, timer);
      }
    }
