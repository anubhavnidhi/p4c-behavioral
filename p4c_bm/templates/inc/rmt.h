/*
Copyright 2013-present Barefoot Networks, Inc. 

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
 * @file
 *
 * @brief Header file for high level interfaces to simulation core
 *
 */

#ifndef _RMT_RMT_H
#define _RMT_RMT_H

/* PLACEHOLDER */
typedef int p4_port_t;

/**
 * @brief Initialize the forwarding simulation
 */

extern void rmt_init(void);

/**
 * @brief Send a packet in for processing
 *
 * @param ingress The ingress port on which the packet was received
 * @param pkt Pointer to the packet data
 * @param len The number of bytes in the packet
 *
 * @return_val 0 Success
 * @return_val -1 Error
 */

extern int rmt_process_pkt(p4_port_t ingress, void *pkt, int len);

/**
 * @brief Function pointer for packet transmit vector
 */

typedef void (*rmt_transmit_vector_f)(p4_port_t egress, void *pkt, int len);

/**
 * @brief Register the transmit function with the forwarding simulation
 *
 * @param tx_fn The transmit function to use (or NULL to deregister)
 */

extern void rmt_transmit_register(rmt_transmit_vector_f tx_fn);

/**
 * @brief Typedef of logging vector
 *
 * Just looks like printf
 */

typedef int (*p4_logging_f)(char *format, ...);

/**
 * @brief Set the logging vector
 *
 * @param log_fn The logging vector; set to NULL to disable logging
 */

extern void rmt_logger_set(p4_logging_f log_fn);

/**
 * @brief Enumeration of logging levels understood by sim
 *
 * Simple linear levels
 */
typedef enum p4_log_level_e {
    P4_LOG_LEVEL_NONE,      /** No output */
    P4_LOG_LEVEL_FATAL,     /** Only fatal errors */
    P4_LOG_LEVEL_ERROR,     /** Errors */
    P4_LOG_LEVEL_WARN,      /** Warnings */
    P4_LOG_LEVEL_INFO,      /** Informational */
    P4_LOG_LEVEL_VERBOSE,   /** Verbose */
    P4_LOG_LEVEL_TRACE,     /** Most fn calls */
} p4_log_level_t;

/**
 * @brief Set the log level for the forwarding code
 *
 * @param level The log level
 */
extern void rmt_log_level_set(p4_log_level_t level);

/**
 * @brief Get the current log level
 */
extern p4_log_level_t rmt_log_level_get(void);


/*
 * Other APIs we expect to need for the simulation
 *
 * Set up the multicast tables
 * Queue configuration
 */

#endif
