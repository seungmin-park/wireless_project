# 인공지능과 라즈베리 파이를 활용한 자동 회전문 속도 제어 프로젝트

## ❕ 프로젝트 목표

버튼을 눌러 속도 조절을 하는 기존 방식과 다르게 자동으로 속도 제어를 하여 휠체어를 탄 사람들의 자동 회전문 사고를 예방합니다.

 딥러닝을 통해 휠체어 모델을 학습시키고, 라즈베리 파이의 카메라 모듈을 통해 휠체어와 사람을 인식하고 분류합니다.
 
 휠체어가 인식된다면 속도를 줄이고, 사람이 인식된다면 정상속도로 작동하게 됩니다.

## 🙍‍♂️ Member

- 박승민, 김연욱, 김현호, 조민호

## 🧰 학습 장비

|장비 이름| 개수|
|:-:|:-:|
|라즈베리 파이 4|3|
|라즈베리 SSD|1|
|라즈베리 파이 3|1|
|웹캠|4|
|아두이노|4|
|신호등 센서|4|
|키보드|1|
|L298N(모터 속도 제어 센서)|1|

## 🛠 사용 기술 및 개발 환경

- yolov5
- 라즈베리 파이 4
- 라즈베리 SSD
- 웹캠
- 아두이노 우노
- 신호등 센서
- L298N
- DC 모터

## 🦾 인공지능

Roboflow에서 데이터셋을 만들고, Yolov5를 활용하여 학습하고 아이와 휠체어를 탄 사람을 인식한다. 

![test_detect_wheelchair](https://user-images.githubusercontent.com/78605779/206113399-b5c2a3b7-0aea-4961-b783-214544902d3f.gif)

> 테스트 데이터 출처: https://www.youtube.com/watch?v=Gnr0yn6vmqM


## 🤷‍♂️ 실행 방법

- Yolov5 설치

    ```bash
    $ git clone https://github.com/ultralytics/yolov5
    ```

    ```bash
    $ pip3 install -r requirements.txt
    ```

- [PyTorch 1.12.0 , torchvision 0.13.0 설치](https://qengineering.eu/install-pytorch-on-raspberry-pi-4.html)

- 아두이노와 시리얼 통신 설정

    ### serial 모듈 import

    ```python
    import serial
    ```

    > 만약 serial 모듈이 없다면 'pip install serial'을 통해서설치

    ### 시리얼 통신 연결

    ```python
    ser = serial.Serial('{SERIAL_PORT}', {BAUDRATE})
    ```

    ### 시리얼 통신 코드 추가

    yolov5에서 객체를 탐지해 결과 생성한 부분 밑에 시리얼통신하고자하는 코드추가

    **yolov5 detecy.py의 결과 출력 코드**

    ```python
    LOGGER.info(f"{s}{'' if len(det) else '(nodetections), '{dt[1].dt * 1E3:.1f}ms")
    ```

    ```python
    # detect wheelchair
    if 'w' in s:
        ser.write("w".encode())
    # detect person
    elif 'p' in s:
        ser.write("p".encode())
    # none detect
    else:
        ser.write("n".encode())
    ```

## 🚨 프로젝트를 진행하며 겪었던 ISSUE

- 성인과 아이 구분

  ![KakaoTalk_Photo_2022-12-07-16-24-33](https://user-images.githubusercontent.com/78605779/206114728-06bbae7e-bc3f-4d92-85b8-d2345b95126d.png)

- 라즈베이 파이에 yolov5 및 pytorch 환경 설정

    **pytorch 1.13 설치 중**

    ![KakaoTalk_Photo_2022-12-07-16-40-46](https://user-images.githubusercontent.com/78605779/206117753-120bf49f-952d-4270-837c-775a470e1018.jpeg)

- 모터 속도 제어
- 장비 부족으로 인한 협업 난항

## 🎥 진행 과정

### yolov5와 아두이노의 시리얼 통신

![test_serial](https://user-images.githubusercontent.com/78605779/206103600-fed5b9f6-aeea-488b-9ac4-3cc6de9424f0.gif)

> 테스트 데이터 출처: https://www.youtube.com/watch?v=XUhPIRwn8a8

### 회전문 프로토타입모델 제작 과정

![creating_prototype_model_2](https://user-images.githubusercontent.com/78605779/206104392-6c022b7f-6b3c-4a8a-8e23-b20b593eb876.jpeg)

![creating_prototype_model_2](https://user-images.githubusercontent.com/78605779/206104395-7c1dd035-7672-49da-bb9e-fb1074904d98.jpeg)

![create_prototype_model](https://user-images.githubusercontent.com/78605779/206104210-78474e6c-0fa3-4cd3-b8da-84960efcbc15.gif)

## 차주 계획

- 성인과 아이 분류 도입
- 모터 속도 제어 개선
- grafana 시각화