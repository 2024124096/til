# 17. Connectivity (연결성)

## 1. 동기: "Connected"를 넘어서

- "connected"(연결요소 1개)만으로는 부족 — 실제 시스템(컴퓨터망, 사회망, 도로망)은 연결되어 있어도 **취약점** 존재
- 핵심 질문:
  - 네트워크가 얼마나 **견고(robust)**한가?
  - 그룹을 분리하려면 몇 개의 edge(friendship)를 제거해야 하는가?
  - 네트워크를 끊으려면 몇 개의 vertex(server)가 고장나야 하는가?
- → **연결성의 정도를 정량화** 필요

## 2. Edge Connectivity (간선 연결성)

- **Edge connectivity**: G를 분리(disconnect)시키기 위해 제거해야 하는 **최소 edge 수**
- **Bridge (다리)**: 제거 시 연결요소 수가 **증가**하는 edge
  - 예: edge 3−4가 bridge면 그것 하나 제거로 그래프 분리 → edge connectivity = 1

## 3. Vertex Connectivity (정점 연결성)

- **Vertex connectivity**: G를 분리시키기 위해 제거해야 하는 **최소 vertex 수**
- **관례**: 완전그래프 Kₙ의 vertex connectivity = **n − 1**
- **Articulation Point (절단점, cut vertex)**: 제거 시 연결요소 수가 **증가**하는 vertex
  - articulation point가 하나라도 있으면 vertex connectivity = 1

## 4. k-Connected & Biconnected

- **k-connected**: vertex connectivity가 **적어도 k**인 그래프
  - 1-connected = 단순히 "connected"
- **Biconnected**: 2-connected 그래프
  - = connected이고 **articulation point가 없음**
- **응용 (network survivability)**:
  - biconnectivity는 네트워크 생존성의 최소 조건
  - biconnected면 **단일 노드가 고장나도** 나머지가 분리되지 않음

## 5. 새로운 관점: Paths vs Cuts

두 정점 s, t의 연결을 두 가지로 분석:
1. **Cuts (Separators)**: s와 t를 분리하려면 몇 개의 edge/vertex를 제거?
2. **Paths (Connectors)**: s와 t 사이 **disjoint path**가 몇 개?

→ 이 둘의 관계를 **Menger의 정리**가 정확히 규명

## 6. Menger's Theorem — 핵심 개념

- **⟨s,t⟩-edge-cut**: 제거하면 s→t path가 남지 않는 edge 집합
- **Edge connectivity of G**: 모든 ⟨s,t⟩ 쌍에 대한 edge-cut 최소 크기
- **Edge-disjoint paths**: 공통 edge가 없는 s→t path들
- **⟨s,t⟩-edge-connector**: 쌍별로 edge-disjoint인 s→t path들의 집합

## 7. Menger's Theorem (정리 17.2)

> **유한 그래프 G의 서로 다른 정점 s, t에 대해:**
> **"최소 ⟨s,t⟩-edge-cut의 크기" = "최대 edge-disjoint s→t path 수"**

**정점 버전** (인접하지 않은 s, t에 대해):
> "최소 ⟨s,t⟩-vertex-cut의 크기" = "최대 vertex-disjoint s→t path 수"

### 증명 구조
"min-cut = max-paths"를 두 부등식으로 분리:
1. **min-cut ≥ max-paths** (쉬움)
2. **min-cut ≤ max-paths** (어려운 부분, Lemma 17.1로 해결)

**Lemma 17.1**: 최소 크기 ⟨s,t⟩-edge-cut C에 대해, C가 각 path의 edge를 하나씩 포함하는 ⟨s,t⟩-edge-connector P가 존재한다.

## 8. 응용: Max-Flow-Min-Cut

- Menger 정리의 weighted digraph 일반화
- edge weight를 "capacity"(대역폭, 수도관 등)로 간주
- **Max-Flow-Min-Cut Theorem**: source→target 최대 flow = ⟨s,t⟩-edge-cut의 최소 capacity
- 알고리즘·최적화의 핵심 결과 (예: **Ford-Fulkerson 알고리즘**)

---
## 핵심 요약 (Takeaways)
- **Edge connectivity**: 분리에 필요한 최소 edge 수
- **Vertex connectivity**: 분리에 필요한 최소 vertex 수
- **Bridge**: 제거 시 연결요소 증가하는 edge
- **Articulation Point**: 제거 시 연결요소 증가하는 vertex
- **Biconnected**: 2-connected (articulation point 없음) — 견고한 망 설계의 핵심
- **Menger's Theorem**: 연결성의 기본 정리 → **Min-cut = Max-disjoint-paths** (edge·vertex 모두 적용)
