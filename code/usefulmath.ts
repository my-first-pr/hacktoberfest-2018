export function clamp(val: number, min: number, max: number): number {
    return Math.min(Math.max(min, val), max);
}

export function lerp(from: number, to: number, t: number): number {
    return from + clamp(t, 0, 1) * (to - from);
}