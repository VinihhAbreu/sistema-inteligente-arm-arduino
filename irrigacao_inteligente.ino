#define sensorUmidade A0
#define rele 7
#define ledVerde 8
#define ledVermelho 9

int valorUmidade = 0;

void setup() {

  pinMode(rele, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  valorUmidade = analogRead(sensorUmidade);

  Serial.print("Umidade: ");
  Serial.println(valorUmidade);

  if(valorUmidade > 700) {

    digitalWrite(rele, HIGH);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);

    Serial.println("Solo seco - Irrigando");

  } else {

    digitalWrite(rele, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);

    Serial.println("Solo umido");

  }

  delay(2000);
}