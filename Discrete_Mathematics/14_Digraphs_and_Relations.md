# 14. Digraphs and Relations (방향그래프와 관계)

## 1. 관계와 Digraph

- **이항관계 R on S**: R ⊆ S × S
- 임의의 이항관계 R을 digraph G = ⟨S, R⟩로 표현
  - S: 정점 집합, R: arc 집합
- "**R(x, y) holds**" ⇔ digraph에 arc x → y 존재 ⇔ ⟨x, y⟩ ∈ R

**예시 (S = {0,1,2,3})**
- **Predecessor 관계**: pred = {⟨m,n⟩ : n = m+1} → arcs: 0→1, 1→2, 2→3. (strict linear order 아님)
- **Less-than 관계**: < = {⟨m,n⟩ : m < n} → arcs: 0→1,0→2,0→3,1→2,1→3,2→3. (strict linear order). pred의 "확장"

## 2. Property 1: Transitivity (이행성)

**정의**: 임의 x,y,z에 대해 R(x,y) ∧ R(y,z) ⇒ R(x,z)
- digraph: x → y → z (길이 2 path)가 있으면 직통 arc x → z 존재
- 모든 (strict) linear order는 transitive
- 일부 비선형 순서도 transitive (예: descendant, reachable)

## 3. Closure (폐포) 개념

- **연산에 대해 닫혀있음(closed)**: S의 원소에 연산을 적용한 결과가 항상 S에 속함
  - ℤ는 덧셈에 닫힘 / 홀수 집합 O는 덧셈에 닫히지 않음 (3+5=8 ∉ O)
- **Transitivity Rule**: R이 ⟨x,y⟩, ⟨y,z⟩를 포함하면 ⟨x,z⟩도 포함해야 함
- R이 transitive ⇔ 이 규칙에 대해 닫혀있음

**Closure**: R이 규칙에 닫혀있지 않으면, R을 포함하는 **가장 작은** 닫힌 집합 R′
- "빠진 쌍"을 모두 추가해 성질을 만족시킴
- 예: R = {⟨x,y⟩,⟨y,z⟩} → transitive closure = {⟨x,y⟩,⟨y,z⟩,⟨x,z⟩}

## 4. Transitive Closure (R⁺)

> **R⁺**: R을 transitive하게 만드는 최소 확장
- R⁺(x,y) ⇔ x=x₀,…,xₙ=y (n>0) 수열이 존재하여 각 R(xᵢ, xᵢ₊₁) 성립
- digraph: **nontrivial reachability** (길이 ≥ 1 path 존재)
- 예: lessThan = pred⁺, descendant = child⁺

## 5. Property 2: Reflexivity (반사성)

- **Reflexive**: 모든 x에 대해 R(x,x) 성립 (모든 정점에 self-loop). 예: ≤, =
- **Irreflexive**: 어떤 x에 대해서도 R(x,x) 불성립 (self-loop 없음). 예: <
- 둘 다 아닐 수도 있음

**Reflexive closure** = R ∪ {⟨x,x⟩ : x ∈ S} (모든 정점에 self-loop 추가)

## 6. Reflexive, Transitive Closure (R*)

- R*: R의 transitive closure에 reflexive closure 적용
- digraph: **full reachability** (길이 ≥ 0 path 존재, trivial 포함)
- **R⁺ = 1보 이상 / R\* = 0보 이상**
- 예: ℕ에서 ≤ = pred의 reflexive-transitive closure
- 응용: R이 프로그램의 single-step 관계면, R*(s_start, s_halt) = "halt 상태 도달 가능?"

## 7. Property 3: Symmetry (대칭성)

- **Symmetric**: R(x,y) ⇒ R(y,x) (모든 arc 양방향). 예: "is married to", 양방향 도로
- **Asymmetric**: R(x,y)와 R(y,x)가 동시에 성립 불가. → **irreflexive 함** (self-loop 없음). 예: <
- **Antisymmetric**: R(x,y) ∧ R(y,x) ⇒ x = y. 예: ≤ (x≤y, y≤x ⇒ x=y), ⊆ (A⊆B, B⊆A ⇒ A=B)

## 8. Key Type 1: Equivalence Relation (동치관계)

**정의**: 다음 세 성질을 모두 만족 (**R-T-S**)
1. **Reflexive**: R(x,x)
2. **Transitive**: R(x,y) ∧ R(y,z) ⇒ R(x,z)
3. **Symmetric**: R(x,y) ⇒ R(y,x)

예: "x는 y와 고향이 같다"

### Partition (분할)
집합 S를 블록(block)들로 빈틈·겹침 없이 나눔. 세 조건:
1. **Non-empty**: 빈 블록 없음
2. **Mutually Disjoint**: 블록끼리 겹치지 않음 (X₁ ∩ X₂ = ∅)
3. **Exhaustive**: 블록들의 합집합 = S

### Theorem 14.2 (동치관계 ↔ 분할)
> 임의의 동치관계 ↔ 는 S를 **동치류(equivalence class)**로 분할한다. 역으로, 임의의 분할은 동치관계를 정의한다.
- 동치류 [x] = {y ∈ S : ⟨x,y⟩ ∈ ↔}
- **R ⇒ Non-empty & Exhaustive / T+S ⇒ Disjoint**

## 9. 응용: Strongly Connected Components (SCC)

- **Mutual Reachability**: R_mutual(x,y) ⇔ R*(x,y) ∧ R*(y,x) (서로 도달 가능)
- 이 관계는 **동치관계** → SCC = mutual reachability의 동치류가 유도하는 maximal subgraph

### Theorem 14.3 (Condensation Graph)
> digraph를 각 SCC를 super-vertex로 "압축(condense)"하면 결과 그래프 G′는 **DAG**이다.
- G′ 정점 = SCC 집합, X→Y arc (X≠Y) ⇔ 원본에 x∈X, y∈Y인 arc 존재
- **왜 DAG?** G′에 cycle 있으면 그 SCC들이 상호 도달 가능 → 하나의 SCC였어야 함 (모순)

## 10. Key Type 2: Partial Order (부분순서)

**정의**: **Reflexive + Transitive + Antisymmetric (R-T-A)**
- 동치관계와 차이: Symmetric 대신 **Antisymmetric**
- 예: ℤ에서 ≤, 멱집합에서 ⊆
- "**partial**"인 이유: 일부 원소는 **비교불가(incomparable)**. 예: ⊆에서 {0}, {1}은 서로 포함 안 됨

### Linear Order vs Partial Order
- **Linear (Total) order**: 모든 쌍이 비교가능한 partial order. 임의 x,y에 대해 x≤y 또는 y≤x. (≤는 linear, ⊆는 아님)
- **Strict partial order**: irreflexive 버전 (Irreflexive + Antisymmetric + Transitive). 예: <, ⊂

### DAG와의 연결
- 임의의 strict partial order의 그래프는 **DAG** (transitive + acyclic)
- 임의의 partial order는 DAG의 **R\* (reflexive-transitive closure)**

## 11. 응용: Prerequisite Graph

- 즉시 선수과목 관계 R = DAG
- R⁺ = strict partial order "~보다 먼저 들어야 함"
- R* = partial order "먼저 또는 동시에 들어야 함"

**Minimal Element (극소원소)**: 다른 어떤 원소보다 "크지" 않은 원소 (예: 선수과목 없는 과목 CS1)
- partial order는 극소원소 여러 개 가능
- 극소원소 찾기 ⇒ **Topological sort 알고리즘**

---
## 핵심 요약 (Takeaways)
| 성질 | 조건 |
|------|------|
| Transitive | x→y ∧ y→z ⇒ x→z |
| Reflexive / Irreflexive | x→x 모두 / 전혀 없음 |
| Symmetric | x→y ⇒ y→x |
| Antisymmetric | x→y ∧ y→x ⇒ x=y |
| Asymmetric | x→y ⇒ ¬(y→x) |

- **R⁺**: nontrivial reachability (길이 >0) / **R\***: full reachability (길이 ≥0)
- **Equivalence (R-T-S)**: 동치류로 분할, SCC가 대표 응용
- **Partial Order (R-T-A)**: 의존성 모델, 비교불가 원소 존재, prereq 그래프
