#ifndef _LIGHTTPD_BASE_H_
#define _LIGHTTPD_BASE_H_

#include <lighttpd/settings.h>

/* Next try to fix strict-alias warning */
#undef ev_init
#define ev_init(ev,cb_) do {                   \
  ev_watcher *ew = (ev_watcher *)(void *)ev;   \
  (ew)->active   =                             \
  (ew)->pending  =                             \
  (ew)->priority = 0;                          \
  ev_set_cb ((ev), cb_);                       \
} while (0)

#undef ev_timer_set
#define ev_timer_set(ev,after_,repeat_) do {   \
  ev_watcher_time *ew = (ev_watcher_time *)(ev); \
  ew->at = (after_);                           \
  (ev)->repeat = (repeat_);                    \
} while (0)

#include <lighttpd/typedefs.h>
#include <lighttpd/module.h>

#include <lighttpd/chunk.h>
#include <lighttpd/chunk_parser.h>

#include <lighttpd/waitqueue.h>

#include <lighttpd/server.h>
#include <lighttpd/worker.h>
#include <lighttpd/condition.h>
#include <lighttpd/options.h>
#include <lighttpd/value.h>
#include <lighttpd/actions.h>
#include <lighttpd/plugin.h>
#include <lighttpd/http_headers.h>
#include <lighttpd/http_request_parser.h>
#include <lighttpd/request.h>
#include <lighttpd/response.h>
#include <lighttpd/virtualrequest.h>
#include <lighttpd/log.h>

#include <lighttpd/connection.h>

#include <lighttpd/network.h>
#include <lighttpd/collect.h>
#include <lighttpd/utils.h>

#define SERVER_VERSION ((guint) 0x01FF0000)

#endif
