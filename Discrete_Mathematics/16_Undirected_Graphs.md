# 16. Undirected Graphs (무방향 그래프)

## 1. Digraph와의 차이

| | Digraph | Undirected Graph |
|---|---|---|
| 연결 | arc (순서쌍 ⟨u,v⟩), u→v ≠ v→u | edge (방향 없음), {x,y} = {y,x} |
| Self-loop | 허용 | **불허** |
| 다중 edge | 같은 방향 1개 | 두 정점 사이 최대 1개 |

## 2. 형식 정의

**Undirected graph**: G = ⟨V, E⟩
- **V**: 정점 집합
- **E**: edge 집합. edge e는 V의 **두 원소 부분집합** {x,y} (= x − y)
- x, y는 edge의 **endpoint**, edge x−y는 x, y에 **incident**

## 3. Walk, Path, Circuit, Cycle (digraph와 미묘한 차이)

| 용어 | 정의 |
|------|------|
| **Walk** | 정점 수열 v₀,…,vₙ (vᵢ₋₁ − vᵢ ∈ E). 길이 = edge 수 n |
| **Path** | **edge**를 반복하지 않는 walk (※ digraph는 정점 기준) |
| **Circuit** | 시작·끝이 같은 **path** (길이 > 0) (※ digraph는 walk 기준) |
| **Cycle** | 시작/끝 정점 외에 정점 반복 없는 circuit |

### Theorem 16.1
> **모든 circuit은 cycle을 포함한다.**

## 4. Connectivity & Distance

- 두 정점 u, v가 **connected** ⇔ 둘 사이 path 존재
- **Connectedness는 동치관계** (R-T-S) → 동치류 = **연결요소(connected component)**
- 그래프가 **connected** ⇔ 연결요소가 1개
- **Distance**: 두 정점 사이 최단 path 길이

## 5. 무방향 ↔ 방향 그래프 변환

- 무방향 → 방향: edge x−y를 양방향 arc x↔y로
  - 무방향의 connected component = 방향그래프의 **SCC**
- 방향 → 무방향(underlying graph): arc x→y를 edge x−y로, 중복 병합, self-loop 제거
  - digraph의 SCC는 underlying graph의 연결요소와 **대응하지 않음** → **WCC(weakly connected component)**라 부름

## 6. Vertex Degree (정점 차수)

- **deg(v)**: 정점 v에 incident한 edge 수
- **Handshaking Lemma**: 모든 정점 차수의 합 = **2|E|** (항상 짝수)
- 그래프 연산:
  - G − v = ⟨V−{v}, E − {edge들 incident to v}⟩
  - G − e = ⟨V, E − {e}⟩
  - G + e = ⟨V, E ∪ {e}⟩

## 7. Eulerian Circuit (오일러 회로)

- **Eulerian circuit**: 그래프의 **모든 edge를 정확히 한 번씩** 지나는 circuit
- 쾨니히스베르크 7개 다리 문제에서 유래 (Euler)

### Theorem 16.2 (Euler's Theorem)
> 연결그래프 G에 Eulerian circuit이 존재 ⇔ **모든 정점의 차수가 짝수**

## 8. Graph Isomorphism (그래프 동형)

- G = ⟨V,E⟩와 G′ = ⟨V′,E′⟩가 **isomorphic** ⇔ 전단사 f: V→V′ 존재하여
  - x−y ∈ E ⇔ f(x)−f(y) ∈ E′ (정점 relabeling으로 G′ 얻음)
- **필요조건** (충분조건 아님!):
  - 같은 정점 수, 같은 edge 수, 같은 **degree spectrum** (각 차수의 정점 수 동일)
- ⚠️ 동형 판별의 간단한 테스트는 아직 미발견

## 9. 특수 그래프: Complete Graph (Kₙ)

- 서로 다른 모든 정점 쌍이 edge로 연결
- 정점 수: n
- edge 수: **n(n-1)/2** (= ₙC₂)
- 모든 정점 차수: **n − 1**
- 지름(diameter): 1 (n > 1)

## 10. Tree (트리)

- **Tree**: **연결되어 있고 acyclic(cycle 없음)**인 그래프
- **Forest**: acyclic 그래프 (각 연결요소가 트리)

### 트리의 동치 성질 (Theorem) — n개 정점
다음은 모두 동치 (하나가 나머지 모두를 함의):
1. (정의) T는 connected & acyclic
2. (Edge count) **T는 connected & 정확히 n−1개 edge**
   - 귀납법: 트리에는 차수 1 정점(leaf)이 ≥1개 존재 → 제거하면 n−1 정점 트리
3. (Path Uniqueness) 임의 두 정점 사이 **유일한 path** 존재 (두 path면 cycle 형성)
4. (Minimally Connected) connected이지만 **어떤 edge를 제거해도 분리됨**
5. (Maximally Acyclic) acyclic이지만 **어떤 edge를 추가해도 cycle 생성**

## 11. Spanning Tree (신장 트리)

- 연결그래프 G의 **spanning tree**: 부분그래프 T로서
  1. T가 트리이고
  2. G의 **모든 정점을 포함** (V를 "span")
- 모든 연결그래프는 spanning tree를 적어도 하나 가짐
- n개 정점이면 spanning tree는 **n−1개 edge**

## 12. Weighted Graph & MST

- **Weighted graph**: 각 edge e에 수치 가중치 w(e) 부여 (거리, 비용, 지연 등)
- 트리 T의 weight w(T) = 모든 edge weight의 합
- **Minimum Spanning Tree (MST)**: spanning tree 중 weight가 최소인 것
  - MST가 여러 개일 수 있음
  - 응용: 모든 도시를 최소 비용으로 연결

## 13. Kruskal's Algorithm

- MST를 찾는 **greedy 알고리즘**
- 아이디어: **cycle을 만들지 않는 한** 가장 싼 edge부터 하나씩 추가

### Theorem 16.6
> Kruskal 알고리즘은 MST를 만든다. (증명: **Invariant Principle**)
- 상태 v = ⟨F, E⟩ (F: 현재까지 선택된 edge들, E: 남은 정렬된 edge 리스트)
- 시작: ⟨∅, E_sorted⟩ (weight 오름차순 정렬)
- 전이: E의 첫 edge e에 대해
  - F ∪ {e}가 cycle 생성 → e 버리고 ⟨F, E_rest⟩
  - cycle 없음 → ⟨F ∪ {e}, E_rest⟩
- **불변식 P⟨F,E⟩: "F는 어떤 MST의 부분그래프"**

---
## 핵심 요약 (Takeaways)
- Undirected Graph ⟨V, E⟩ = 대칭 관계 모델
- **Handshaking Lemma**: Σ deg(v) = 2|E|
- **Euler's Theorem**: Eulerian circuit ⇔ 모든 정점 차수 짝수
- **Tree**: connected & acyclic, n 정점 ⇒ n−1 edge, 두 정점 사이 유일 path
- **Spanning Tree** → 모든 정점 연결 / **MST** = 최소 weight spanning tree
- **Kruskal**: cycle 안 만들며 싼 edge부터 추가하는 greedy MST 알고리즘
