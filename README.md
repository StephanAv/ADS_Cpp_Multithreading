# ADS C++ Multithreading 

In this example, 25 threads are spawned each of them creating an object of type ADS_Access which creates a connection to the local TC1000 ADS router and starts reading the local ADS state every 1000 ms, 5 times total.

![screenshot_multithreading_sample.jpg](screenshot_multithreading_sample.jpg?raw=true)
The example makes use of the [extended funtions](https://infosys.beckhoff.com/content/1033/tc3_adsdll2/117533963.html?id=4578956694695684431  ) for multithreaded applications.

