# Coin Counter (동전 개수 세기 프로그램)
이 프로젝트는 OpenCV를 활용하여 이미지에서 동전을 감지하고, 동전의 개수를 계산하는 프로그램입니다. 제공된 이미지에서 동전을 검출하고 결과를 시각적으로 확인할 수 있습니다.

## 주요 기능
1. **이미지 로드**: 프로그램은 총 6개의 동전 이미지를 로드합니다.
2. **이미지 전처리**: Gaussian 블러링을 통해 노이즈를 제거합니다.
3. **동전 검출**: HoughCircles 알고리즘을 사용하여 이미지에서 동전을 감지합니다.
4. **결과 비교**: 실제 동전 개수와 검출된 개수를 비교하여 출력합니다.
5. **시각화**: 검출된 동전을 이미지에 표시하고 화면에 출력합니다.


## 실행 방법

### 1. 필수 라이브러리 설치
이 프로젝트는 OpenCV 라이브러리를 사용합니다. 다음 명령어를 통해 OpenCV를 설치하세요:
```bash
pip install opencv-python opencv-python-headless
```

### 2. 코드 실행
1. 코드를 클론하거나 다운로드합니다:
   ```bash
   git clone https://github.com/your-repository/coin-counter.git
   cd coin-counter
   ```
2. 동전 이미지(`coins0.jpg`, `coins1.jpg`, ... `coins5.jpg`)를 적절한 경로에 배치합니다.
3. `coincounter.cpp` 파일을 컴파일 및 실행합니다:
   ```bash
   g++ coincounter.cpp -o coincounter `pkg-config --cflags --libs opencv4`
   ./coincounter
   ```


## 파일 구조
```
coin-counter/
├── coincounter.cpp   # 메인 소스 코드
├── images/           # 동전 이미지 파일들
└── README.md         # 프로젝트 설명 파일
```


## 코드 설명
- **이미지 로드**:
  프로그램은 `imread`를 통해 6개의 동전 이미지를 불러옵니다. 경로는 수정이 필요할 수 있습니다.
- **동전 검출**:
  Gaussian 블러링과 HoughCircles 알고리즘을 사용하여 동전을 검출합니다.
- **시각화**:
  `circle` 함수를 사용하여 검출된 동전을 이미지에 표시합니다.


## 향후 개선 사항
1. **파일 경로 설정**: 코드에서 하드코딩된 파일 경로를 사용자 입력 또는 설정 파일로 대체.
2. **파라미터 튜닝**: 이미지에 따라 HoughCircles의 파라미터를 자동 조정하도록 개선.
3. **결과 저장**: 처리된 이미지를 파일로 저장하는 기능 추가.
4. **정확도 개선**: 더 정교한 알고리즘을 추가하여 정확도를 높임.


## 참고 자료
- OpenCV 공식 문서: [https://docs.opencv.org](https://docs.opencv.org)
- Hough Transform 원리: [Wikipedia](https://en.wikipedia.org/wiki/Hough_transform)
