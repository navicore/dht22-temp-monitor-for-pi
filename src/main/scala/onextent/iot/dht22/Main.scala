package onextent.iot.dht22

object Main {

  def main(args: Array[String]): Unit = {

    val dht22 = new Dht22

    val reading1: Array[Float] = dht22.get(4)

    println(s"reading1 c: ${reading1(0)}")
    println(s"reading1 f: ${reading1(1)}")
    println(s"reading1 h: ${reading1(2)}")

    val reading2: Array[Float] = dht22.get(22)

    println(s"reading2 c: ${reading2(0)}")
    println(s"reading2 f: ${reading2(1)}")
    println(s"reading2 h: ${reading2(2)}")


  }

}

