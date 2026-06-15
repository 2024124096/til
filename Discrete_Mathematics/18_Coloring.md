# 18. Coloring (그래프 색칠)

## 1. 동기: Scheduling Problem

- 6명 과학자(A~F)가 5개 장비(1~5)를 사용, 여러 명이 같은 장비 필요
- 충돌하는 작업은 같은 시간 블록에 배정 불가
- **Q. 모든 작업에 필요한 최소 1시간 블록 수는?**

### Conflict Graph (충돌 그래프)로 모델링
- **정점 V**: 과학자 {A,B,C,D,E,F}
- **edge E**: 충돌 — 동시에 일할 수 없는 두 과학자 (장비 공유) 사이에 edge

## 2. Graph Coloring 도입

- 각 정점에 "색(color)" 배정
- **규칙**: 인접한(edge로 연결된) 두 정점은 **다른 색**을 가져야 함
- 연결:
  - **색 = 시간 슬롯**
  - 같은 색 정점은 충돌 없음 → 같은 시간 슬롯 배정 가능
  - (예: 3색만 쓰면 6개 대신 3개 시간 블록으로 충분)

## 3. 형식 정의

- **Coloring of G = ⟨V,E⟩**: 함수 c: V → C
  - C는 고정된 유한 색 집합
  - 모든 edge {x,y} ∈ E에 대해 **c(x) ≠ c(y)**
- **k-coloring**: k개 색을 사용하는 coloring (|{c(v) : v∈V}| = k)
- **Chromatic Number χ(G)**: G가 k-coloring을 가지는 **최소 k**

### 예: Chromatic Number 구하기
- Q. G가 2-colorable? → **No**, A,B,C가 삼각형(K₃) 형성, 셋 다 서로 인접
- 일반: **G′ ⊆ G 이면 χ(G′) ≤ χ(G)**
- Q. G가 3-colorable? → **Yes**, 3-coloring 발견
- χ(G) ≥ 3 이고 3-coloring 존재 → **χ(G) = 3**

## 4. 주요 그래프의 Chromatic Number

| 그래프 | χ |
|--------|---|
| **Complete graph Kₙ** | **n** (모든 정점이 서로 인접, 모두 다른 색 필요) |
| **Path graph Pₙ** (n>1) | **2** (두 색 교대 A-B-A-B-…) |
| **Tree** (nontrivial) | **2** (Pₙ의 일반화) |

- **Clique** (완전 부분그래프 Kₖ)는 chromatic number의 **하한(lower bound)** 결정: χ(G) ≥ k

## 5. 특수 경우: 2-Colorability (Bipartite)

- **Bipartite (이분 그래프)**: 정점을 두 disjoint 집합 A, B로 나눠 **모든 edge가 A의 정점과 B의 정점을 연결**
  - 같은 집합 내부(A-A, B-B)에는 edge 없음
- **G가 2-colorable ⇔ G가 bipartite** (A는 파랑, B는 빨강)
- **G가 bipartite ⇔ odd-length cycle이 없음**
  - 길이 3, 5 등 홀수 cycle은 2-colorable 아님

## 6. Chromatic Number의 한계 (Bounds)

- 정확한 χ(G) 계산은 매우 어려움 (**NP-complete**) → 보통 bound 사용

**1. Clique bound (하한)**
- k-clique = 완전 부분그래프 Kₖ
- G가 k-clique를 포함하면 **χ(G) ≥ k** (반드시 써야 하는 최소)

**2. Degree bound (상한)**
- k = G의 정점 중 최대 차수
- **χ(G) ≤ k + 1** (절대 넘지 않을 최대)

## 7. 응용 1: Register Allocation (레지스터 할당)

- 컴파일러가 프로그램 변수를 소수의 빠른 CPU 레지스터에 배정
- 두 변수가 동시에 "alive"(미래에 값 필요)면 같은 레지스터 불가
- 모델:
  - **정점 = 변수**, **edge = 충돌**(동시에 alive), **색 = 레지스터**
  - 목표: χ(G) = 필요한 최소 레지스터 수

## 8. 응용 2: Gate Scheduling (게이트 배정)

- 도착 항공편에 공항 게이트 배정
- 충돌 규칙: 도착 시간이 1시간 미만 차이면 같은 게이트 불가
- 모델: 정점=항공편, edge=충돌, 색=게이트
- 예: BCDE가 K₄(4-clique) → χ(G) ≥ 4, 4-coloring 발견 → **χ(G) = 4**

## 9. The Four-Color Theorem (4색 정리)

- Q. 인접한 두 지역이 다른 색이 되도록 지도를 칠하려면 몇 색?
- 2D 지도 → **planar graph(평면 그래프)**로 변환
  - 정점 = 지역, edge = 공유 국경
  - planar = edge가 교차하지 않게 그릴 수 있음
- **Four-Color Theorem (Appel & Haken, 1976)**:
  > **모든 planar graph는 4-colorable** (G가 planar면 χ(G) ≤ 4)
- 컴퓨터의 도움으로 증명된 최초의 주요 정리

---
## 핵심 요약 (Takeaways)
- **Graph coloring**: 인접 정점이 다른 색을 갖도록 색 배정
- **Chromatic number χ(G)**: k-coloring을 위한 최소 k
- **χ(G) ≥ k** if G가 k-clique(Kₖ) 포함 (clique 하한)
- **χ(G) ≤ (최대 차수) + 1** (degree 상한)
- **χ(Pₙ) = 2** (n>1), **χ(nontrivial tree) = 2**
- **2-colorable ⇔ bipartite ⇔ odd cycle 없음**
- **Four-color theorem**: planar 그래프면 χ(G) ≤ 4
- 응용: 스케줄링, 레지스터 할당, 게이트 배정 등 충돌 문제
