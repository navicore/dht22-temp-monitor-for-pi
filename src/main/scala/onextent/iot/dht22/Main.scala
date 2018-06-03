package onextent.iot.dht22

object Main {

  def main(args: Array[String]): Unit = {

    val dht22 = new Dht22

    val reading: Array[Float] = dht22.get()

    println(s"reading c: ${reading(0)}")
    println(s"reading f: ${reading(1)}")
    println(s"reading h: ${reading(2)}")

  }

}

