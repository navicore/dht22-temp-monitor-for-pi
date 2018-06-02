DHT22 Temp Monitor for PI
-----

a JNI project generated from navicore/navijni.g8

Build and run via:
```console
sbt assembly
java -jar target/scala-2.12/Dht22TempMonitorForPi.jar
```

  * scala app built in the root project
  * cpp native lib built in a sub-project dependency
  * root project superjar via JniPackage and assembly plugin contains native shared libs - ready to run

