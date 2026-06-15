# 13. Directed Graphs (방향 그래프)

## 1. 기본 정의

**Digraph (방향 그래프)**: 순서쌍 ⟨V, A⟩
- **V**: 정점(vertices, nodes)의 비어있지 않은 집합
- **A ⊆ V × V**: 호(arcs, edges)의 집합 → **이항관계(binary relation)를 표현**
- arc 표기: ⟨v, w⟩ 대신 v → w

**핵심 특징**
- **Self-loop**: 자기 자신으로 가는 arc 허용 (c → c)
- **Bi-directional arc**: 두 정점 사이 양방향 arc 가능 (b → d, d → b)
- **Isolated vertex**: 어떤 arc에도 속하지 않는 정점 가능
- **제약**: A는 집합이므로 같은 방향 arc는 최대 1개

## 2. Walk, Path, Circuit, Cycle

| 용어 | 정의 |
|------|------|
| **Walk** | arc를 따라가는 정점 수열 v₀,…,vₙ (vᵢ → vᵢ₊₁ ∈ A). 길이 = arc 개수 n |
| **Path** | 정점을 반복하지 않는 walk (cycle 없음) |
| **Circuit** | 시작·끝 정점이 같은 walk |
| **Cycle** | 시작/끝 정점만 반복되는 circuit |

- **Trivial path/cycle**: 길이 0 (임의 정점 → 자기 자신)
- **Nontrivial**: 길이 > 0
- **Acyclic digraph (DAG)**: nontrivial cycle이 없는 digraph

## 3. Walk와 Path의 관계 (중요)

> **v에서 w로 가는 walk가 있으면, v에서 w로 가는 path도 존재한다.**

**증명 아이디어**: path가 아닌 walk는 반드시 cycle을 포함. cycle을 "잘라내면" 더 짧은 walk가 됨.
- walk v₀ → … → vₙ 에서 vᵢ = vⱼ (i < j)인 cycle 발견 시
- v₀ → … → vᵢ → vⱼ₊₁ → … → vₙ 로 축소
- cycle이 없어질 때까지 반복 → path

## 4. Reachability & Distance

- **Reachable**: v에서 w로 가는 path(walk)가 있으면 w는 v에서 reachable
- **Distance dG(v, w)**: v→w 최단 path의 길이. path 없으면 ∞
- **Nontrivially reachable**: 길이 > 0인 walk로 도달
  - "reachable이면서 w ≠ v"와 **동치 아님** (v→v nontrivial cycle 가능)

## 5. Strongly Connected & Subgraph

- **Strongly connected digraph**: 모든 정점이 다른 모든 정점에서 reachable
- **Subgraph**: ⟨V′, A′⟩ where V′ ⊆ V, A′ ⊆ A, A′의 모든 arc는 V′ 내 정점 사이
- **Induced subgraph (V′가 유도하는 부분그래프)**: V′의 두 끝점을 모두 가진 A의 모든 arc 포함

## 6. Degree와 DAG

- **In-degree**: 정점으로 들어오는 arc 수
- **Out-degree**: 정점에서 나가는 arc 수
- **Source**: in-degree = 0인 정점
- **Sink**: out-degree = 0인 정점
- DAG는 source/sink를 여러 개 가질 수 있음

### Theorem 13.3 (핵심)
> **유한(finite) DAG는 적어도 하나의 source와 하나의 sink를 가진다.**

**증명 (sink 존재, 귀류법)**:
1. sink가 없다고 가정 → 모든 정점의 out-degree > 0
2. 임의 v₀에서 시작 → v₀ → v₁ → v₂ → … 무한히 walk 생성 가능
3. V는 유한집합 → 무한 walk는 반드시 정점 반복 → cycle 발생
4. DAG(acyclic)라는 전제와 모순 → 가정 거짓, sink 존재

⚠️ **이 정리는 유한 DAG에만 적용** (무한 DAG는 sink 없을 수 있음)

## 7. Tournament Graph (특수 경우)

- 서로 다른 모든 정점 쌍이 **정확히 한 방향** arc로 연결 (양방향 X)
- 라운드 로빈 토너먼트 모델 (무승부 없음)
- n-정점 토너먼트의 arc 수 = **n(n-1)/2 = ₙC₂**

## 8. Linear Order & Strict Linear Order

- **Linear order (⪯, total order)**: S = s₀,…,sₙ 로 나열 가능, sᵢ ⪯ sⱼ ⇔ i ≤ j
- **Strict linear order (≺)**: sᵢ ≺ sⱼ ⇔ i < j
  - x ⪯ x 는 성립, x ≺ x 는 불성립

### Theorem (토너먼트와 순서)
> **토너먼트 digraph가 strict linear order를 표현 ⇔ 그것이 DAG이다.**

## 9. 무한 Digraph 예외

- **Predecessor relation on ℕ**: V = {0,1,2,…}, A = {m → n : n = m+1}
  - 0 → 1 → 2 → 3 → ⋯
  - DAG임 (cycle 없음), source(0) 있음, **sink 없음**

---
## 핵심 요약 (Takeaways)
- Digraph ⟨V, A⟩ = 이항관계 표현
- Walk ⊇ Path / Circuit ⊇ Cycle
- Distance = 최단 path 길이
- Strongly connected = 모든 정점 상호 도달
- DAG = nontrivial cycle 없음 → **유한 DAG는 source/sink 보유**
- Tournament graph가 DAG ⇔ strict linear order 표현
