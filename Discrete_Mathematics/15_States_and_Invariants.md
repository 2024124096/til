# 15. States and Invariants (상태와 불변식)

## 1. 디지털 컴퓨터의 상태

- 디지털 컴퓨터의 상태는 **이산적(discrete)** → 한 상태에서 다른 상태로 점프
- CPU 레지스터·메모리 값은 이산집합 중 하나만 가짐 (예: 이진수)
- 디지털 부품은 0, 1 두 상태만 → **n비트면 2ⁿ 상태** (비트 수에 따라 지수적 증가)
- digraph로 컴퓨터를 모델링 가능

## 2. 이산 시스템 모델링

- 임의의 이산상태 시스템 = digraph로 모델
  - **정점 = 상태**, **arc = 상태 간 전이(transition)** (= 연산/명령)
  - arc에 **레이블(label)**을 붙여 서로 다른 전이 구분
- 이 digraph는 시스템의 **동작(behavior)**을 표현 (내부 구조·구현과 독립)

## 3. State Space (상태공간) 정의

**State space**: 쌍 ⟨V, A⟩
- **V**: 상태 집합
- **A**: 레이블 붙은 arc 집합 → 삼중쌍 ⟨x, a, y⟩
  - x = 시작 상태, y = 끝 상태, a = 레이블
  - 표기: x —ᵃ→ y

**Underlying digraph**: 레이블을 무시하면 일반 digraph
- arc ⟨x,y⟩ 존재 ⇔ 어떤 레이블 a에 대해 x —ᵃ→ y 존재

**예시 (두 값 추적 컴퓨터)**
- V = ℕ × ℕ, ∑ = {a, b}
- A = {⟨m,n⟩ —ᵃ→ ⟨m+1, n⟩} ∪ {⟨m,n⟩ —ᵇ→ ⟨m, n+1⟩}
- Example 15.2: 상태 ⟨0,0⟩에서 시작, a가 m번·b가 n번 포함된 입력을 읽으면 상태 ⟨m,n⟩
  - 입력 문자열 길이 l에 대한 **수학적 귀납법**으로 증명

## 4. The Invariant Principle (불변식 원리) — 핵심

### Theorem 15.3 (Invariant Principle)
state space ⟨V, A⟩와 상태에 대한 술어 P(v)가 다음을 만족하면:

1. **Initialization (Base Case)**: 시작 상태 v₀에서 P(v₀) 참
2. **Preservation (Maintenance)**: 모든 전이가 P를 보존
   - 임의 전이 x —ᵃ→ y에 대해, P(x) 참이면 P(y)도 참

**그러면 (결론)**:
> **v₀에서 reachable한 모든 상태 v에서 P(v)가 성립한다.** 이 P를 **불변식(invariant)**이라 함.

### 주의: "Reachable"
- 불변식 원리는 **시작 상태에서 도달 가능한** 상태에만 적용
- 예: 시작 0, 전이 x —+1→ x+1, P(n) ≡ "n ≥ 0"
  - 도달 가능 상태 {0,1,2,…}에서 P 참
  - P(−1)이 거짓이어도 무방 — 상태 −1은 **unreachable**하므로 원리 적용 대상 아님

## 5. 주요 응용: 알고리즘 정확성 증명

### Euclid's Algorithm (GCD 계산)
```
Input m, n
1: p, q ← m, n
2: While q ≠ 0:
3:    p, q ← q, p mod q
4: Return p
```
예: m=20, n=14 → ⟨20,14⟩→⟨14,6⟩→⟨6,2⟩→⟨2,0⟩

### 정확성 증명 (Invariant Principle 적용)

**구성 요소**
- 상태 V: ℕ × ℕ
- 시작 상태 v₀: ⟨m, n⟩
- 전이 A: ⟨p,q⟩ → ⟨q, p mod q⟩ (q ≠ 0)
- **불변식 P⟨p,q⟩ ≡ "GCD(p,q) = GCD(m,n)"**

**1. Initialization**: P⟨m,n⟩ ≡ "GCD(m,n)=GCD(m,n)" → 자명하게 참

**2. Preservation**: GCD(p,q) = GCD(q, p mod q) 증명
- Lemma: r = p mod q 라 하면 p = k·q + r (k ∈ ℕ)
- p, q의 공약수는 r = p − k·q 도 나눔
- q, r의 공약수는 p = k·q + r 도 나눔
- ⟹ ⟨p,q⟩와 ⟨q,r⟩는 **공약수 집합이 동일** ⟹ GCD 동일

**3. Termination (종료)**: q(둘째 성분)가 매 단계 감소
- p mod q < q, p mod q ≥ 0 → 결국 p mod q = 0
- 종료 시 상태 ⟨r, 0⟩, P⟨r,0⟩ ≡ "GCD(r,0)=GCD(m,n)"
- 정의상 GCD(r,0) = r ⟹ **r = GCD(m,n)** → 알고리즘 정확

> ⚠️ 불변식 원리만으로는 "종료하면 정확함"까지만 보장. **종료 증명은 별도로** 필요.

---
## 핵심 요약 (Takeaways)
- **State Space ⟨V, A⟩**: 상태 집합 V + 레이블 arc 집합 A. 전이 x —ᵃ→ y
- **Invariant**: 시작 상태에서 참이고 모든 전이에서 보존되는 술어
- **Invariant Principle**: 불변식은 모든 **reachable** 상태에서 참
- **응용**: 알고리즘 정확성 형식 증명 (예: Euclid의 GCD)
