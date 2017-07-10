#ifndef _SRC_H_
#define _SRC_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm.h>

class src_unit : sc_core::sc_module, tlm::tlm_bw_transport_if<> {
public:
  SC_CTOR(src_unit) {
    // register SystemC threads
    SC_THREAD(generate);
    init_socket.bind(*this);
  }


  tlm::tlm_initiator_socket<> init_socket;

  
  void generate();
	void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range) {};
  tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload& trans,
			tlm::tlm_phase& phase, sc_core::sc_time& t) { return tlm::TLM_COMPLETED; }

}; // END SC_MODULE "src_unit"

#endif

