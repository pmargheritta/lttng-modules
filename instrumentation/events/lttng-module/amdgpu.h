#undef TRACE_SYSTEM
#define TRACE_SYSTEM amdgpu

#if !defined(LTTNG_TRACE_AMDGPU_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_AMDGPU_H

#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/tracepoint.h>

LTTNG_TRACEPOINT_EVENT(amdgpu_bo_create,
	TP_PROTO(void *bo),
	TP_ARGS(bo),
	TP_FIELDS(
		ctf_integer_hex(int, bo_addr, bo)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_cs,
	TP_PROTO(void *p, int i),
	TP_ARGS(p, i),
	TP_FIELDS(
		ctf_integer_hex(int, p_addr, p)
		ctf_integer(int, i, i)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_grab_id,
	TP_PROTO(unsigned vmid, int ring),
	TP_ARGS(vmid, ring),
	TP_FIELDS(
		ctf_integer(unsigned, vmid, vmid)
		ctf_integer(int, ring, ring)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_bo_map,
	TP_PROTO(void *bo_va, void *mapping),
	TP_ARGS(bo_va, mapping),
	TP_FIELDS(
		ctf_integer_hex(int, bo_va_addr, bo_va)
		ctf_integer_hex(int, mapping_addr, mapping)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_bo_unmap,
	TP_PROTO(void *bo_va, void *mapping),
	TP_ARGS(bo_va, mapping),
	TP_FIELDS(
		ctf_integer_hex(int, bo_va_addr, bo_va)
		ctf_integer_hex(int, mapping_addr, mapping)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_bo_update,
	TP_PROTO(void *mapping),
	TP_ARGS(mapping),
	TP_FIELDS(
		ctf_integer_hex(int, mapping_addr, mapping)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_set_page,
	TP_PROTO(uint64_t pe, uint64_t addr, unsigned count, 
		 uint32_t incr, uint32_t flags),
	TP_ARGS(pe, addr, count, incr, flags),
	TP_FIELDS(
		ctf_integer(uint64_t, pe, pe)
		ctf_integer(uint64_t, addr, addr)
		ctf_integer(unsigned, count, count)
		ctf_integer(uint32_t, incr, incr)
		ctf_integer(uint32_t, flags, flags)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_vm_flush,
	TP_PROTO(uint64_t pd_addr, unsigned ring, unsigned id), 
	TP_ARGS(pd_addr, ring, id),
	TP_FIELDS(
		ctf_integer(uint64_t, pd_addr, pd_addr)
		ctf_integer(unsigned, ring, ring)
		ctf_integer(unsigned, id, id)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_bo_list_set,
	TP_PROTO(void *list, void *bo),
	TP_ARGS(list, bo),
	TP_FIELDS(
		ctf_integer_hex(int, list_addr, list)
		ctf_integer_hex(int, bo_addr, bo)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_fence_emit,
	TP_PROTO(void *dev, int ring, u32 seqno),
	TP_ARGS(dev, ring, seqno),
	TP_FIELDS(
		ctf_integer_hex(int, dev_addr, dev)
		ctf_integer(int, ring, ring)
		ctf_integer(u32, seqno, seqno)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_fence_wait_begin,
	TP_PROTO(void *dev, int ring, u32 seqno),
	TP_ARGS(dev, ring, seqno),
	TP_FIELDS(
		ctf_integer_hex(int, dev_addr, dev)
		ctf_integer(int, ring, ring)
		ctf_integer(u32, seqno, seqno)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_fence_wait_end,
	TP_PROTO(void *dev, int ring, u32 seqno),
	TP_ARGS(dev, ring, seqno),
	TP_FIELDS(
		ctf_integer_hex(int, dev_addr, dev)
		ctf_integer(int, ring, ring)
		ctf_integer(u32, seqno, seqno)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_semaphore_signale,
	TP_PROTO(int ring, void *sem),
	TP_ARGS(ring, sem),
	TP_FIELDS(
		ctf_integer(int, ring, ring)
		ctf_integer_hex(int, sem_addr, sem)
	)
)

LTTNG_TRACEPOINT_EVENT(amdgpu_semaphore_wait,
	TP_PROTO(int ring, void *sem),
	TP_ARGS(ring, sem),
	TP_FIELDS(
		ctf_integer(int, ring, ring)
		ctf_integer_hex(int, sem_addr, sem)
	)
)

#endif /* !defined(LTTNG_TRACE_AMDGPU_H) || defined(TRACE_HEADER_MULTI_READ) */

#include "../../../probes/define_trace.h"

