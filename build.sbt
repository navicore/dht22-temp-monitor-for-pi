name := "Dht22TempMonitorForPi"

version := "1.0"

scalaVersion := "2.12.6"

libraryDependencies ++=
  Seq(
    "org.scalatest" %% "scalatest" % "3.0.5" % "test"
  )

lazy val main = Project(id = "Dht22TempMonitorForPi", base = file(".")).dependsOn(native % Runtime)

lazy val native = (project in file("native")).
  settings(sourceDirectory in nativeCompile := sourceDirectory.value).
  enablePlugins(JniNative)

mainClass in assembly := Some("onextent.iot.dht22.Main")
assemblyJarName in assembly := "Dht22TempMonitorForPi.jar"

(Test / test) := ((Test / test) dependsOn javah).value

